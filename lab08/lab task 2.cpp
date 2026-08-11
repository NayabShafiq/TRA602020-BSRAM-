#include <iostream>
using namespace std;
class SensorLog
{
private:
    string sensorID;
    float* data;     
    int capacity;
    int count;
public:
    SensorLog(string id, int cap)
        : sensorID(id), capacity(cap)
    {
        count=0;
        data=new float[capacity];
        for(int i=0;i<capacity;i++)
        {
            data[i]=0.0f;
        }
        cout<<"[Constructor] Log '" <<sensorID <<"' created. Capacity: "<<capacity <<endl;
    }
    SensorLog(const SensorLog& other)
    {
        sensorID=other.sensorID + "_copy";
        capacity=other.capacity;
        count=other.count;
        data=new float[capacity];
        for(int i=0;i<capacity;i++)
        {
            data[i]=other.data[i];
        }
        cout<<"[Copy Constructor] Log '"<<sensorID<<"' cloned."<<endl;
    }
    ~SensorLog()
    {
        delete[] data;
        cout<<"[Destructor] Log '"<<sensorID<<"' memory freed."<<endl;
    }
    void addReading(float val)
    {
        if(count>=capacity)
        {

            cout<<"Log '"<<sensorID<<"' full. Cannot add."<<endl;
        }
        else
        {
            data[count]=val;
            count++;
            cout<<"Log '"<<sensorID<<"' recorded: "<<val<<endl;
        }
    }
    void display() const
    {
        cout<<"Log ["<<sensorID<<"] ("<<count<<"/"<<capacity<<"): ";
        for(int i=0;i<count;i++)
        {
            cout<<data[i]<< " ";
        }
        cout<<endl;
    }
};
int main()
{
    SensorLog log1("Ultrasonic-01",4);
    log1.addReading(12.5f);
    log1.addReading(33.1f);
    log1.addReading(45.8f);
    log1.addReading(22.0f);
    log1.addReading(99.9f);
    cout<<"---Copy log---"<<endl;
    SensorLog log2(log1);
    log2.display();
    cout<<"---Display original---"<<endl;
    log1.display();
    cout<<"---Heap log---"<<endl;
    SensorLog* log3=new SensorLog("LiDAR-01",2);
    log3->addReading(5.0f);
    log3->display();
    delete log3;
    cout<<"---End---"<<endl;
    return 0;
}
