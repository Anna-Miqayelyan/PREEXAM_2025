#include <iostream>
#include <vector>
#include <list>
#include <mutex>
#include <array>
using namespace std;

class HashTable{
static const int size =5;
struct Item{
    int key;
    string value;
};
vector<list<Item>> table;
array<mutex,size> locks;

int hashFunc(int key){
    return key% size;
}
public:
   HashTable() {
        table.resize(size);
    }

void insert (int key, string value){
    int index=hashFunc(key);
    lock_guard<mutex> lock(locks[index]);
    for (auto& item:table[index]){
        if(item.key==key){
            item.value=value;
            return;
        }
    }
    table[index].push_back({key,value});
}
void display(){
    for (int i=0;i<size;++i){
        lock_guard<mutex>lock(locks[i]);
        cout<<"Bucket"<<i<<": ";
        if(table[i].empty()) cout<<"EMPTY:";
        else {
            for(auto& item :table[i]){
                cout <<"["<<item.key<<" : "<<item.value<<"] ";
            }
        }
        cout<<endl;
    }
}

void find(int key){
    for (int i=0; i<size;i++){
        int index=hashFunc(key);
        lock_guard<mutex> lock(locks[index]);
        for (auto& item:table[index]){
            if(item.key==key){
                cout<<key<<" is found with vslue of "<<item.value<<endl;
                return;
            }
        }

    }
}
void remove(int key){
    int index=hashFunc(key);
    lock_guard<mutex> lock(locks[index]);
    table[index].remove_if([key](const Item& item){
      return item.key==key;
    });
}
};
int main(){
    HashTable ht;
    ht.insert(1,"apple");
    ht.insert(2,"Bananan");
    ht.insert(7,"avocado");

    ht.display();
    ht.remove(2);
    ht.display();
    ht.find(7);
    return 0;
}