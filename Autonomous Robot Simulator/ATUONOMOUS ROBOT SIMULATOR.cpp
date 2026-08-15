/*
    AUTONOMOUS ROBOT SIMULATOR
    ---------------------------
    Matches the report architecture:
      - Environment Manager
      - Sensor Module (Sensor -> ObstacleSensor, Inheritance)
      - Path Planner (A* Algorithm)
      - Robot Controller (uses Sensor + PathPlanner)
      - Visualisation Module (SFML)

    Compile (MSYS2/g++):
      g++ AutonomousRobotSimulator.cpp -o simulator.exe -lsfml-graphics -lsfml-window -lsfml-system

    Controls:
      Left Click  -> set/toggle obstacle
      Right Click -> set Start position
      Middle Click / Shift+Click -> set Goal position
      SPACE       -> run A* and start robot movement
      R           -> reset grid
*/

#include <SFML/Graphics.hpp>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

enum class MovementMode {
    FourWay,
    EightWay
};

const int ROWS = 20;
const int COLS = 30;
const float CELL = 30.f;

// ---------------------- Node (used by A*) ----------------------
struct Node {
    int x, y;
    float g, h;
    Node* parent;
    float f() const { return g + h; }
};

// ---------------------- 1. Environment Manager ----------------------
class Environment {
public:
    std::vector<std::vector<bool>> obstacles; // true = blocked

    Environment() {
        obstacles.assign(ROWS, std::vector<bool>(COLS, false));
    }

    bool isFree(int x, int y) const {
        if (x < 0 || y < 0 || x >= COLS || y >= ROWS) return false;
        return !obstacles[y][x];
    }

    void addObstacle(int x, int y) {
        if (x >= 0 && y >= 0 && x < COLS && y < ROWS)
            obstacles[y][x] = true;
    }

    void toggleObstacle(int x, int y) {
        if (x >= 0 && y >= 0 && x < COLS && y < ROWS)
            obstacles[y][x] = !obstacles[y][x];
    }

    void reset() {
        obstacles.assign(ROWS, std::vector<bool>(COLS, false));
    }

    bool saveToFile(const std::string& path, const sf::Vector2i& start,
                    const sf::Vector2i& goal, MovementMode mode) const {
        std::ofstream out(path);
        if (!out) return false;

        out << start.x << ' ' << start.y << '\n'
            << goal.x << ' ' << goal.y << '\n'
            << (mode == MovementMode::EightWay ? 1 : 0) << '\n';

        for (int y = 0; y < ROWS; ++y) {
            for (int x = 0; x < COLS; ++x)
                out << (obstacles[y][x] ? '1' : '0');
            out << '\n';
        }

        return true;
    }

    bool loadFromFile(const std::string& path, sf::Vector2i& start,
                      sf::Vector2i& goal, MovementMode& mode) {
        std::ifstream in(path);
        if (!in) return false;

        int sx, sy, gx, gy, m;
        if (!(in >> sx >> sy >> gx >> gy >> m)) return false;

        start = {sx, sy};
        goal = {gx, gy};
        mode = (m == 1 ? MovementMode::EightWay : MovementMode::FourWay);

        obstacles.assign(ROWS, std::vector<bool>(COLS, false));
        std::string line;
        std::getline(in, line);

        for (int y = 0; y < ROWS; ++y) {
            if (!std::getline(in, line) || static_cast<int>(line.size()) < COLS)
                return false;
            for (int x = 0; x < COLS; ++x)
                obstacles[y][x] = (line[x] == '1');
        }

        return true;
    }
};

// ---------------------- 2. Sensor Module (Inheritance) ----------------------
class Sensor {
protected:
    int range;
public:
    Sensor(int r = 1) : range(r) {}
    virtual bool detectObstacle(const Environment& env, int x, int y) {
        return !env.isFree(x, y); // base behaviour
    }
    virtual ~Sensor() {}
};

class ObstacleSensor : public Sensor {
public:
    ObstacleSensor(int r = 1) : Sensor(r) {}
    bool detectObstacle(const Environment& env, int x, int y) override {
        // specific logic: checks the cell directly ahead
        return !env.isFree(x, y);
    }
};

// ---------------------- 3. Path Planner (A*) ----------------------
class PathPlanner {
public:
    bool hasLineOfSight(const Environment& env, sf::Vector2i a, sf::Vector2i b) const {
        int dx = std::abs(b.x - a.x);
        int dy = std::abs(b.y - a.y);
        int sx = a.x < b.x ? 1 : -1;
        int sy = a.y < b.y ? 1 : -1;
        int err = dx - dy;

        int x = a.x;
        int y = a.y;

        while (true) {
            if (!env.isFree(x, y) && !(x == a.x && y == a.y) && !(x == b.x && y == b.y))
                return false;
            if (x == b.x && y == b.y)
                break;

            int prevX = x;
            int prevY = y;
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x += sx;
            }
            if (e2 < dx) {
                err += dx;
                y += sy;
            }

            if (!env.isFree(x, y) && !(x == b.x && y == b.y))
                return false;
            if (x != prevX && y != prevY) {
                if (!env.isFree(x, prevY) || !env.isFree(prevX, y))
                    return false;
            }
        }
        return true;
    }

    bool canJump(const Environment& env, int cx, int cy, const sf::Vector2i& direction, sf::Vector2i& landing) const {
        if (direction.x != 0 && direction.y != 0)
            return false;

        int midx = cx + direction.x;
        int midy = cy + direction.y;
        int nx = cx + direction.x * 2;
        int ny = cy + direction.y * 2;

        if (nx < 0 || ny < 0 || nx >= COLS || ny >= ROWS)
            return false;

        if (!env.isFree(midx, midy) && env.isFree(nx, ny)) {
            landing = {nx, ny};
            return true;
        }
        return false;
    }

    bool canMove(const Environment& env, int cx, int cy, const sf::Vector2i& direction) const {
        int nx = cx + direction.x;
        int ny = cy + direction.y;
        if (!env.isFree(nx, ny))
            return false;

        if (direction.x != 0 && direction.y != 0) {
            if (!env.isFree(cx + direction.x, cy) || !env.isFree(cx, cy + direction.y))
                return false;
        }

        return true;
    }

    std::vector<sf::Vector2i> simplifyPath(const Environment& env, const std::vector<sf::Vector2i>& rawPath) const {
        if (rawPath.size() < 3) return rawPath;

        std::vector<sf::Vector2i> smooth;
        smooth.push_back(rawPath.front());
        size_t anchor = 0;

        for (size_t next = 1; next < rawPath.size(); ++next) {
            if (!hasLineOfSight(env, rawPath[anchor], rawPath[next])) {
                smooth.push_back(rawPath[next - 1]);
                anchor = next - 1;
            }
        }

        smooth.push_back(rawPath.back());
        return smooth;
    }

    std::vector<sf::Vector2i> findPath(const Environment& env,
                                        sf::Vector2i start, sf::Vector2i goal,
                                        MovementMode mode = MovementMode::EightWay) {
        auto heuristic = [](sf::Vector2i a, sf::Vector2i b) {
            return std::sqrt(static_cast<float>((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
        };

        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::vector<sf::Vector2i> directions;
        directions.push_back({0, 1});
        directions.push_back({0, -1});
        directions.push_back({1, 0});
        directions.push_back({-1, 0});
        if (mode == MovementMode::EightWay) {
            directions.push_back({1, 1});
            directions.push_back({1, -1});
            directions.push_back({-1, 1});
            directions.push_back({-1, -1});
        }

        auto cmp = [](Node* a, Node* b) { return a->f() > b->f(); };
        std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openSet(cmp);

        std::vector<Node*> allNodes;
        Node* startNode = new Node{start.x, start.y, 0, heuristic(start, goal), nullptr};
        openSet.push(startNode);
        allNodes.push_back(startNode);

        Node* goalNode = nullptr;

        while (!openSet.empty()) {
            Node* current = openSet.top();
            openSet.pop();

            if (visited[current->y][current->x]) continue;
            visited[current->y][current->x] = true;

            if (current->x == goal.x && current->y == goal.y) {
                goalNode = current;
                break;
            }

            for (auto direction : directions) {
                int nx = current->x + direction.x;
                int ny = current->y + direction.y;
                if (nx < 0 || ny < 0 || nx >= COLS || ny >= ROWS)
                    continue;

                if (canMove(env, current->x, current->y, direction) && !visited[ny][nx]) {
                    float cost = (direction.x != 0 && direction.y != 0) ? 1.414f : 1.f;
                    Node* neighbor = new Node{nx, ny, current->g + cost,
                                               heuristic({nx, ny}, goal), current};
                    openSet.push(neighbor);
                    allNodes.push_back(neighbor);
                } else {
                    sf::Vector2i landing;
                    if (canJump(env, current->x, current->y, direction, landing) && !visited[landing.y][landing.x]) {
                        float cost = 2.2f;
                        Node* neighbor = new Node{landing.x, landing.y, current->g + cost,
                                                   heuristic(landing, goal), current};
                        openSet.push(neighbor);
                        allNodes.push_back(neighbor);
                    }
                }
            }
        }

        std::vector<sf::Vector2i> path;
        if (goalNode) {
            for (Node* n = goalNode; n; n = n->parent)
                path.push_back({n->x, n->y});
            std::reverse(path.begin(), path.end());
        }

        for (auto n : allNodes) delete n;
        return path;
    }
};

// ---------------------- 4. Robot Controller ----------------------
class Robot {
public:
    sf::Vector2i position;
    sf::Vector2f renderPosition;
    float speed;
    Sensor* sensor;
    std::vector<sf::Vector2i> path;
    size_t pathIndex = 0;
    bool moving = false;
    bool blocked = false;
    sf::Vector2i target;
    float progress = 0.f;
    float stepDuration = 0.1f;
    float animationPhase = 0.f;
    float angleDegrees = 0.f;
    float targetAngle = 0.f;
    float rotationSpeed = 360.f;
    bool jumpMessage = false;
    float jumpMessageTimer = 0.f;
    static constexpr float jumpMessageDuration = 1.5f;

    Robot(sf::Vector2i startPos) : position(startPos), renderPosition(startPos.x * CELL + CELL / 2.f, startPos.y * CELL + CELL / 2.f), speed(2.f) {
        sensor = new ObstacleSensor();
    }

    ~Robot() { delete sensor; }

    static float normalizeAngle(float angle) {
        while (angle < 0.f) angle += 360.f;
        while (angle >= 360.f) angle -= 360.f;
        return angle;
    }

    static float shortestAngleDiff(float from, float to) {
        float diff = normalizeAngle(to - from);
        if (diff > 180.f) diff -= 360.f;
        return diff;
    }

    void initStep() {
        if (pathIndex >= path.size()) {
            moving = false;
            return;
        }

        target = path[pathIndex];
        float dx = static_cast<float>(target.x - position.x);
        float dy = static_cast<float>(target.y - position.y);
        targetAngle = normalizeAngle(std::atan2(dy, dx) * 180.f / 3.14159265f);

        float distance = std::hypot(dx, dy);
        stepDuration = std::max(0.05f, distance / speed);
        progress = 0.f;
        jumpMessage = distance > 1.9f;
        if (jumpMessage)
            jumpMessageTimer = jumpMessageDuration;
    }

    void setPath(const std::vector<sf::Vector2i>& p) {
        path = p;
        pathIndex = 1;
        blocked = false;
        moving = (path.size() > 1);
        progress = 0.f;
        ensurePosition();
        if (moving) {
            initStep();
        }
    }

    void update(const Environment& env, float deltaSeconds) {
        if (!moving || pathIndex >= path.size()) return;
        if (sensor->detectObstacle(env, target.x, target.y)) {
            moving = false;
            blocked = true;
            progress = 0.f;
            ensurePosition();
            return;
        }

        if (jumpMessageTimer > 0.f) {
            jumpMessageTimer -= deltaSeconds;
            if (jumpMessageTimer <= 0.f) {
                jumpMessageTimer = 0.f;
                jumpMessage = false;
            }
        }

        float angleDiff = shortestAngleDiff(angleDegrees, targetAngle);
        float maxTurn = rotationSpeed * deltaSeconds;
        if (std::abs(angleDiff) <= maxTurn) {
            angleDegrees = targetAngle;
        } else {
            angleDegrees = normalizeAngle(angleDegrees + (angleDiff > 0.f ? maxTurn : -maxTurn));
        }

        progress += deltaSeconds / stepDuration;
        animationPhase += deltaSeconds * 6.f;
        if (animationPhase > 2.f * 3.14159265f) animationPhase -= 2.f * 3.14159265f;

        sf::Vector2f startPos(position.x * CELL + CELL / 2.f, position.y * CELL + CELL / 2.f);
        sf::Vector2f endPos(target.x * CELL + CELL / 2.f, target.y * CELL + CELL / 2.f);
        renderPosition = startPos + (endPos - startPos) * std::min(progress, 1.f);

        if (progress >= 1.f) {
            position = target;
            renderPosition = endPos;
            pathIndex++;
            if (pathIndex >= path.size()) {
                moving = false;
            } else {
                initStep();
            }
        }
    }

    void ensurePosition() {
        renderPosition = {position.x * CELL + CELL / 2.f, position.y * CELL + CELL / 2.f};
    }

    void display(sf::RenderWindow& window) {
        float pulse = 0.2f + 0.1f * std::sin(animationPhase * 2.f);
        sf::CircleShape body(CELL * 0.2f);
        body.setFillColor(sf::Color(255, 180, 80));
        body.setOutlineThickness(3.f);
        body.setOutlineColor(sf::Color(220, 140, 40));
        body.setOrigin(sf::Vector2f(body.getRadius(), body.getRadius()));
        body.setPosition(renderPosition);
        window.draw(body);

        sf::RectangleShape direction(sf::Vector2f(CELL * 0.35f, 3.f));
        direction.setFillColor(sf::Color::White);
        direction.setOrigin(sf::Vector2f(0.f, 1.5f));
        direction.setPosition(renderPosition);
        direction.setRotation(sf::degrees(angleDegrees));
        window.draw(direction);

        sf::CircleShape pulseDot(CELL * 0.08f);
        pulseDot.setFillColor(sf::Color(255, 120, 60));
        pulseDot.setOrigin(sf::Vector2f(pulseDot.getRadius(), pulseDot.getRadius()));
        pulseDot.setPosition(sf::Vector2f(renderPosition.x, renderPosition.y + pulse * 1.5f));
        window.draw(pulseDot);
    }
};

// ---------------------- 5. Visualisation Module ----------------------
void drawGrid(sf::RenderWindow& window, const Environment& env,
              const std::vector<sf::Vector2i>& path,
              sf::Vector2i start, sf::Vector2i goal) {

    // floor tiles
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            sf::RectangleShape tile(sf::Vector2f(CELL - 1.f, CELL - 1.f));
            tile.setPosition({x * CELL, y * CELL});
            bool odd = (x + y) % 2 == 0;
            tile.setFillColor(odd ? sf::Color(45, 45, 45) : sf::Color(40, 40, 40));
            window.draw(tile);
        }
    }

    // aisle lines
    for (int x = 0; x <= COLS; x++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x * CELL, 0.f), sf::Color(100, 100, 30)),
            sf::Vertex(sf::Vector2f(x * CELL, ROWS * CELL), sf::Color(100, 100, 30))
        };
        window.draw(line, 2, sf::PrimitiveType::Lines);
    }
    for (int y = 0; y <= ROWS; y++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0.f, y * CELL), sf::Color(100, 100, 30)),
            sf::Vertex(sf::Vector2f(COLS * CELL, y * CELL), sf::Color(100, 100, 30))
        };
        window.draw(line, 2, sf::PrimitiveType::Lines);
    }

    // obstacles as crates
    for (int y = 0; y < ROWS; y++)
        for (int x = 0; x < COLS; x++)
            if (env.obstacles[y][x]) {
                sf::RectangleShape block(sf::Vector2f(CELL - 4.f, CELL - 4.f));
                block.setPosition({x * CELL + 2.f, y * CELL + 2.f});
                block.setFillColor(sf::Color(120, 70, 30));
                block.setOutlineThickness(2.f);
                block.setOutlineColor(sf::Color(170, 120, 60));
                window.draw(block);
                sf::RectangleShape stripe(sf::Vector2f(CELL - 8.f, 4.f));
                stripe.setFillColor(sf::Color(210, 190, 120));
                stripe.setPosition({x * CELL + 4.f, y * CELL + CELL * 0.35f});
                window.draw(stripe);
                stripe.setPosition({x * CELL + 4.f, y * CELL + CELL * 0.55f});
                window.draw(stripe);
            }

    // path
    for (auto& p : path) {
        sf::RectangleShape mark(sf::Vector2f(CELL - 1.f, CELL - 1.f));
        mark.setPosition({p.x * CELL, p.y * CELL});
        mark.setFillColor(sf::Color(150, 220, 150));
        window.draw(mark);
    }

    // start
    sf::RectangleShape s(sf::Vector2f(CELL - 1.f, CELL - 1.f));
    s.setPosition({start.x * CELL, start.y * CELL});
    s.setFillColor(sf::Color::Green);
    window.draw(s);

    // goal
    sf::RectangleShape g(sf::Vector2f(CELL - 1.f, CELL - 1.f));
    g.setPosition({goal.x * CELL, goal.y * CELL});
    g.setFillColor(sf::Color::Red);
    window.draw(g);
}

void drawHud(sf::RenderWindow& window, const sf::Font& font, bool fontLoaded,
             bool autoReplan, MovementMode mode, float speed,
             const sf::Vector2i& start, const sf::Vector2i& goal,
             const std::vector<sf::Vector2i>& path, bool moving, bool jumpMessage) {
    if (!fontLoaded) return;

    std::ostringstream ss;
    ss << "Start: [" << start.x << "," << start.y << "]   Goal: [" << goal.x << "," << goal.y << "]\n";
    ss << "Mode: " << (mode == MovementMode::EightWay ? "8-way" : "4-way")
       << "   Auto: " << (autoReplan ? "ON" : "OFF")
       << "   Speed: " << speed << " cells/sec\n";
    ss << "Status: " << (moving ? "Moving" : "Stopped")
       << "   Path: " << (path.empty() ? "none" : std::to_string(path.size()) + " steps") << "\n";
    ss << "Controls: LMB toggle obstacle  Shift+LMB set goal  RMB set start\n"
       << "Space=plan/run  R=reset  S=save  L=load  M=mode  A=auto  Up/Down=speed  Esc=exit";

    sf::Text text(font, ss.str());
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(12.f, 12.f));
    text.setLineSpacing(1.2f);
    text.setOutlineColor(sf::Color(10, 10, 10));
    text.setOutlineThickness(1.f);
    window.draw(text);

    if (jumpMessage) {
        sf::RectangleShape alertBg(sf::Vector2f(260.f, 60.f));
        alertBg.setFillColor(sf::Color(60, 40, 10, 220));
        alertBg.setOutlineThickness(2.f);
        alertBg.setOutlineColor(sf::Color(220, 180, 80));
        alertBg.setPosition(sf::Vector2f(COLS * CELL - 270.f, 12.f));
        window.draw(alertBg);

        sf::Text alert(font, "JUMP! Robot is hopping over a blocked path.");
        alert.setCharacterSize(18);
        alert.setFillColor(sf::Color(255, 230, 120));
        alert.setPosition(sf::Vector2f(COLS * CELL - 262.f, 20.f));
        alert.setOutlineColor(sf::Color(40, 20, 0));
        alert.setOutlineThickness(1.f);
        window.draw(alert);
    }
}

// ---------------------- MAIN ----------------------
int main() {
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(COLS * CELL), static_cast<unsigned int>(ROWS * CELL)}), "Autonomous Robot Simulator");
    window.setFramerateLimit(10); // controls robot step speed

    Environment env;
    PathPlanner planner;

    sf::Vector2i start(1, 1);
    sf::Vector2i goal(COLS - 2, ROWS - 2);
    MovementMode mode = MovementMode::EightWay;
    bool autoReplan = true;
    float speed = 1.f;
    const std::string mapFile = "sim_map.txt";

    sf::Font font;
    bool fontLoaded = font.openFromFile("C:/Windows/Fonts/arial.ttf");
    if (!fontLoaded) {
        std::cerr << "Warning: default font not found. HUD text will be hidden." << std::endl;
    }

    Robot robot(start);
    sf::Clock frameClock;

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                break;
            }

            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                int gx = mousePressed->position.x / static_cast<int>(CELL);
                int gy = mousePressed->position.y / static_cast<int>(CELL);
                if (gx >= 0 && gy >= 0 && gx < COLS && gy < ROWS) {
                    bool shift = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)
                                 || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift);
                    if (mousePressed->button == sf::Mouse::Button::Left) {
                        if (shift)
                            goal = {gx, gy};
                        else
                            env.toggleObstacle(gx, gy);
                    } else if (mousePressed->button == sf::Mouse::Button::Right) {
                        start = {gx, gy};
                    } else if (mousePressed->button == sf::Mouse::Button::Middle) {
                        goal = {gx, gy};
                    }

                    if (autoReplan && robot.moving) {
                        auto newPath = planner.findPath(env, robot.position, goal, mode);
                        robot.setPath(newPath);
                    }
                }
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                    robot.position = start;
                    robot.ensurePosition();
                    auto path = planner.findPath(env, start, goal, mode);
                    robot.setPath(path);
                } else if (keyPressed->code == sf::Keyboard::Key::R) {
                    env.reset();
                    robot.path.clear();
                    robot.position = start;
                    robot.ensurePosition();
                    robot.moving = false;
                } else if (keyPressed->code == sf::Keyboard::Key::S) {
                    if (!env.saveToFile(mapFile, start, goal, mode))
                        std::cerr << "Failed to save map to " << mapFile << std::endl;
                } else if (keyPressed->code == sf::Keyboard::Key::L) {
                    if (env.loadFromFile(mapFile, start, goal, mode)) {
                        robot.path.clear();
                        robot.position = start;
                        robot.ensurePosition();
                        robot.moving = false;
                    } else {
                        std::cerr << "Failed to load map from " << mapFile << std::endl;
                    }
                } else if (keyPressed->code == sf::Keyboard::Key::M) {
                    mode = (mode == MovementMode::EightWay ? MovementMode::FourWay : MovementMode::EightWay);
                } else if (keyPressed->code == sf::Keyboard::Key::A) {
                    autoReplan = !autoReplan;
                } else if (keyPressed->code == sf::Keyboard::Key::Up) {
                    speed = std::min(8.f, speed + 0.5f);
                    robot.speed = speed;
                } else if (keyPressed->code == sf::Keyboard::Key::Down) {
                    speed = std::max(0.5f, speed - 0.5f);
                    robot.speed = speed;
                } else if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                    break;
                }
            }
        }

        float deltaSeconds = frameClock.restart().asSeconds();
        robot.speed = speed;
        robot.update(env, deltaSeconds);

        if (robot.blocked) {
            auto correctedPath = planner.findPath(env, robot.position, goal, mode);
            if (correctedPath.size() > 1) {
                robot.setPath(correctedPath);
            } else {
                robot.blocked = false;
            }
        }

        window.clear(sf::Color(20, 20, 20));
        drawGrid(window, env, robot.path, start, goal);
        drawHud(window, font, fontLoaded, autoReplan, mode, speed, start, goal, robot.path, robot.moving, robot.jumpMessageTimer > 0.f);
        robot.display(window);
        window.display();
    }

    return 0;
}