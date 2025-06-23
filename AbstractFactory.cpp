#include <iostream>
using namespace std;

class Weapon{
    public:
    virtual void use()=0;
};
class Armor{
    public:
    virtual void wear()=0;
};

class ElfArmor:public Armor{
public:
void wear()override{
    cout<<"Elf wears light green armor\n";

}
};
class ElfWeapon:public Weapon{
    public:
    void use() override{
        cout<<"Elf uses a magic wand:\n";
    }
};
class OrcWeapon:public Weapon{
    public:
    void use() override
{    cout<<"Orc  uses a heavy axe\n ";
}
};
class OrcArmor:public Armor{
    public:
    void wear() override{
        cout<<"Orc wears iron armor:\n";
    }


};

class CharacterFactory{
    public:
    virtual Weapon* createWeapon()=0;
    virtual Armor* createArmor()=0;
};

class ElfFactory:public CharacterFactory{
    public :
    Weapon* createWeapon() override {
        return new ElfWeapon();
    }
    Armor* createArmor()override {
        return new ElfArmor();
    }
};
class OrcFactory:public CharacterFactory{
    public:
    Weapon* createWeapon() override {
        return new OrcWeapon();
    }
   Armor* createArmor() {
    return new OrcArmor();
   } 
} ;

//client code??
void createCharacter(CharacterFactory* factory){
    Weapon* weapon=factory->createWeapon();
    Armor* armor=factory->createArmor();

    weapon->use();
    armor->wear();
}
int main(){
    CharacterFactory* factory;
    factory=new ElfFactory();
    createCharacter(factory);
}