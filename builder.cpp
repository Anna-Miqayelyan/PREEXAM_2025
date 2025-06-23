#include <iostream>
#include <string>
using namespace std;
//producttt
class Student{
    public:
    string name;
    int age;
    string university;
    string major;

    void show(){
        cout<<"Student info:\n";
        cout<<"Name: "<<name<<endl<<"AGE: "<<age<<endl<<"University: "<<university<<endl<<"Major: "<<major<<endl;

    }
};

//builderr

class StudentBuilder{
    private:
    Student* student;
    public:
    StudentBuilder(){
        student=new Student();
    }

    StudentBuilder* setName(string n){
        student->name=n;
        return this;
    }
    StudentBuilder* setAge(int a){
        student->age=a;
        return this;
    }
    StudentBuilder* setUnversity(string u){
        student->university=u;
    return this;
    }
    StudentBuilder* setMajor(string m){
        student->major=m;
        return this;
    }
    Student* build(){
        return student;
    }
};

int main(){
    StudentBuilder sb;
   sb.setName("ANNA");
   sb.setAge(20);
   sb.setUnversity("NPUA");
   sb.setMajor("Software Engineer");
  Student* s=sb.build();
  s->show();




}