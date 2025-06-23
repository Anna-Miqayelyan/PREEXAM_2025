#include <iostream>
#include <string>
using namespace std;

// ---- Բարդ օբյեկտ (Product) ----
class Computer {
public:
    string cpu;
    string ram;
    string storage;
    string gpu;

    void show() {
        cout << "Computer Specs:\n";
        cout << "- CPU: " << cpu << endl;
        cout << "- RAM: " << ram << endl;
        cout << "- Storage: " << storage << endl;
        cout << "- GPU: " << gpu << endl;
    }
};

// ---- Builder ինտերֆեյս ----
class ComputerBuilder {
public:
    virtual void setCPU() = 0;
    virtual void setRAM() = 0;
    virtual void setStorage() = 0;
    virtual void setGPU() = 0;
    virtual Computer* getComputer() = 0;
    virtual ~ComputerBuilder() {}
};

// ---- Կոնկրետ Builder ----
class GamingComputerBuilder : public ComputerBuilder {
    Computer* comp;
public:
    GamingComputerBuilder() {
        comp = new Computer();
    }

    void setCPU() override {
        comp->cpu = "Intel Core i9";
    }

    void setRAM() override {
        comp->ram = "32GB DDR5";
    }

    void setStorage() override {
        comp->storage = "1TB SSD";
    }

    void setGPU() override {
        comp->gpu = "NVIDIA RTX 4090";
    }

    Computer* getComputer() override {
        return comp;
    }
};

// ---- Director ----
class Technician {
public:
    void buildComputer(ComputerBuilder* builder) {
        builder->setCPU();
        builder->setRAM();
        builder->setStorage();
        builder->setGPU();
    }
};

// ---- Գլխավոր ----
int main() {
    ComputerBuilder* builder = new GamingComputerBuilder();
    Technician tech;

    tech.buildComputer(builder);
    Computer* pc = builder->getComputer();
    pc->show();

    delete pc;
    delete builder;

    return 0;
}
