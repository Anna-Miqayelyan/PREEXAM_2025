#include <iostream>
using namespace std;

class Singleton{
public:
static Singleton* instance;
Singleton(){
    cout<<"Eager Singleton created: "<<endl;
}
static Singleton* getInstance(){
  return instance;}
};
Singleton* Singleton::instance=new Singleton();
int main(){
    Singleton* a=  Singleton::getInstance();

    return 0;

}