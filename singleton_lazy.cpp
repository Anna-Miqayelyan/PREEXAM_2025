#include <iostream>
#include <mutex>
using namespace std;

class Singleton{
    public:
    static Singleton* instance;
    Singleton(){};

    static Singleton* getInstance(){
        if(instance==nullptr){
            instance=new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;
int main(){
    Singleton* a=Singleton::getInstance();
     Singleton* b = Singleton::getInstance();

    cout << (a == b ? "Same instance\n" : "Different instance\n");
    return 0;
}