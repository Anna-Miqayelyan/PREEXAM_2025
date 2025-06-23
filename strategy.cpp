#include <iostream>
using namespace std;

class AttackStrategy{
    public:
    virtual void attack()=0;
};

class SwordAttack:public AttackStrategy{
    public:
    void attack() override{
        cout<<"Attacking with a sword!"<<endl;
    }
};
class MagicAttack: public AttackStrategy{
    public:
    void attack() override{
        cout<<"Attacking with a magic!"<<endl;
    }
};
class ArrowAttack:public AttackStrategy{
    public:
    void attack() override{
    cout<<"Attacking with an arrow!"<<endl;
}};

class Character{
    public:
    AttackStrategy* strategy;
        void setStrategy(AttackStrategy* s) {
        strategy = s;
    }
    void performAttack(){
        if(strategy) strategy->attack();
        else cout<<"No attack found"<<endl;
    }
};

int main(){
    Character hero;
    hero.setStrategy(new MagicAttack());
    hero.performAttack();
      hero.setStrategy(new ArrowAttack());
    hero.performAttack();
}