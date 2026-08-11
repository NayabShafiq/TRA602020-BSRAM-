#include<iostream>
using namespace std;
class RobotArm
{
private:
    string armName;
    int numJoints;
    string* jointNames;
    float* jointAngles;
    float maxReach;
public:
    RobotArm()
    {
        armName="DefaultArm";
        numJoints=3;
        maxReach=50.0f;
        jointNames=new string[numJoints];
        jointAngles=new float[numJoints];
        jointNames[0]="J1";
        jointNames[1]="J2";
        jointNames[2]="J3";
        for(int i=0;i<numJoints;i++)
        {
            jointAngles[i]=0.0f;
        }
        cout<<"[Default Constructor] "<<armName<<" created. Joints: "<<numJoints<<endl;
    }
    RobotArm(string name,int joints,string names[],float reach)
    {
        armName=name;
        numJoints=joints;
        maxReach=reach;
        jointNames=new string[numJoints];
        jointAngles=new float[numJoints];
        for(int i=0;i<numJoints;i++)
        {
            jointNames[i]=names[i];
            jointAngles[i]=0.0f;
        }
        cout<<"[Param Constructor] "<<armName<<" created. Joints: "<<numJoints<<endl;
    }
    RobotArm(const RobotArm& other)
    {
        armName=other.armName+"_copy";
        numJoints=other.numJoints;
        maxReach=other.maxReach;
        jointNames=new string[numJoints];
        jointAngles=new float[numJoints];
        for(int i=0;i<numJoints;i++)
        {
            jointNames[i]=other.jointNames[i];
            jointAngles[i]=other.jointAngles[i];
        }
        cout<<"[Copy Constructor] "<<armName<<" cloned. Joints: "<<numJoints<<endl;
    }
    ~RobotArm()
    {
        delete[] jointNames;
        delete[] jointAngles;
        cout<<"[Destructor] "<<armName<<" shut down. Memory freed."<<endl;
    }
    void setAngle(int jointIndex,float angle)
    {
        if(angle>180)
        {
            angle=180;
        }
        else if(angle<0)
        {
            angle=0;
        }
        jointAngles[jointIndex]=angle;
        cout<<"Joint["<<jointIndex<<"] "<<jointNames[jointIndex]<<" set to "<<angle<<" deg."<<endl;
    }
    void displayArm() const
    {
        cout<<"--- "<<armName<<" Status ---"<<endl;
        cout<<"Arm: "<<armName<<" | Max Reach: "<<maxReach<<" cm"<<endl;
        for(int i=0;i<numJoints;i++)
        {
            cout<<"Joint["<<i<<"] "<<jointNames[i]<<" : "<<jointAngles[i]<<" deg"<<endl;
        }
        cout<<"Total angle: "<<totalAngle()<<" deg"<<endl;
    }
    float totalAngle() const
    {
        float sum=0;
        for(int i=0;i<numJoints;i++)
        {
            sum=sum+jointAngles[i];
        }
        return sum;
    }
};
int main()
{
    RobotArm arm1;
    string joints[4]={"Shoulder","Elbow","Wrist","Gripper"};
    RobotArm arm2("Arm-Delta",4,joints,120.0f);
    RobotArm arm3(arm2);
    arm2.setAngle(0,45);
    arm2.setAngle(1,90);
    arm2.setAngle(2,30);
    arm2.displayArm();
    arm3.displayArm();
    return 0;
}
