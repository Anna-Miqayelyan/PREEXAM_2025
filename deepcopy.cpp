#include <iostream>
using namespace std;
class Deep{
    public:
    int* data;
Deep(int val){
    data=new int(val);
}
Deep (const Deep& other){
data=new int(*other.data);
}
void show(){
    cout<<"DEEP value: "<<*data<<" ADDR: "<<data<<endl;
}

};
int main(){
    Deep d(20);
    Deep a=d;
    a=15;

    d.show();
    a.show();

}