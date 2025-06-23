#include <iostream>
using namespace std;

class European{
    public:
    virtual void PlugIN()=0;
};
class American{
    public:
    void AmericanConnect(){
        cout<<"Connecting American plug.."<<endl;
    }
};
class Adapter: public European{
    public:
    American* am;
    
    Adapter(American* device) {
        am = device;
    }

 void PlugIN() override{
    cout<<"Connectin Europian"<<endl;
    am->AmericanConnect();

 }
};
int main(){
    American* usdevice=new American();
    European* adapter=new Adapter(usdevice);
    adapter->PlugIN();
}
