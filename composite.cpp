#include <iostream>
#include <vector>
using namespace std;

class BookComponent{
    public:
    virtual void display()=0;

};
class Book: public BookComponent{
    string title;
    public:
    Book(string t):title(t){}
    void display() override {
        cout<<"BOOK: "<<title<<endl;
    }
};
class Library:public BookComponent{
    vector<BookComponent* > books;
    public:
    void add(BookComponent* b){
        books.push_back(b);
    }
    void display()override{
        cout<<"Library contains: "<<endl;
        for(auto b:books){
            b->display();
        }
    }
};

int main(){
    Book* b1=new Book("Dostoyevsky");
    Book* b2=new Book("Albert Camue");
    Library* lib=new Library();
    lib->add(b1);
    lib->add(b2);

    lib->display();
}