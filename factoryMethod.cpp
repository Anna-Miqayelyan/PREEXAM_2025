#include <iostream>
using namespace std;

class Vehicle{
public:
virtual void drive()=0;
};
class Car:public Vehicle{
    public:
    void drive() override{
        cout<<"Driving a car"<<endl;
    }
};
class Bike: public Vehicle{
    public:
    void drive() override{
        cout<<"Riding a bike"<<endl;
    }
};
class VehicleFactory{
    public:
    static Vehicle* createVehicle(const string& type){
        if(type=="car") return new Car();
        else if (type=="bike") return new Bike();
        else return nullptr;
    }
};

int main(){
    Vehicle* v1=VehicleFactory::createVehicle("car");
    v1->drive();
    Vehicle* v2=VehicleFactory::createVehicle("bike");
    v2->drive();
}