#include <iostream>
using namespace std;
class Deep{
    public:
    int* data;
Deep(int val){
    data=new int(val);
}
Deep (const Deep& other){
data=other.data;
}
void show(){
    cout<<"DEEP value: "<<*data<<" ADDR: "<<data<<endl;
}

};
int main(){
    Deep d(20);
    Deep a=d;
d=24;

    d.show();
    a.show();

}