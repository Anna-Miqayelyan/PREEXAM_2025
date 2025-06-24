#include <iostream>
#include <string>
using namespace std;

class Character{
    public:
    virtual Character* clone()=0;
    virtual void show()=0;

};
class Warrior:public Character{
    string name;
    int age;
    public:
    Warrior(string n,int a): name(n),age(a){}
    void show() override{
        cout<<"Warrior: "<<name<<", Age: "<<age<<endl;
    }
  Character* clone() override{
    return new Warrior(name,age);
  }
};
int main(){
    Character* original=new Warrior("Aragorn",40);
    Character* copy=original->clone();

    cout<<"Original: ";
    original->show();

    cout <<"Clone: ";
    copy->show();
}