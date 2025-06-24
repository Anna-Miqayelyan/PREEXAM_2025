#include <iostream>
using namespace std;

class Book{
public:
virtual void read()=0;

};
class RealBook: public Book{
    string title;
    public:
    RealBook(string t): title(t){
        cout<<"Downloading...: "<<title << endl;

    }
    void read( ) override{
        cout<<"Reading: "<<title<<endl;
    }

};
class ProxyBook:public Book{
    string title;
    RealBook* realbook;
    public:
    ProxyBook(string t): title(t),realbook(nullptr){}
    void read() override{
        if(realbook==nullptr)
        realbook=new RealBook(title);
        realbook->read();
    }
};
int main(){
    Book* b= new ProxyBook("Harry Potter");
    b->read();

    cout<<endl<<endl;
    b->read();
}