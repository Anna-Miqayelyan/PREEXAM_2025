#include <iostream>
#include<list>
#include<vector>
using namespace std;

class HashSEt{
    static const int size= 5;
    vector<list<int>> table;
    int hashFunc(int key){
        return key%size;
    }
public:
HashSEt(){table.resize(size);}

void insert(int key){
    int index=hashFunc(key);
    for(int val:table[index]){
        if (val==key) return;
        
    }
    table[index].push_back(key);
}
void display(){
for (int i=0;i<size;i++){
    cout<<"BUCKET: "<< i<<" : ";
    for(int val:table[i]){
        cout<<val<<" ";

    }
    cout<<endl;
}
}
void remove(int key){
    int index=hashFunc(key);
    table[index].remove_if([key](int val){
        return val==key;
    });
}
};

int main(){
HashSEt hs;
hs.insert(20);
hs.insert(30);
hs.insert(21);
hs.insert(32);
hs.display();
hs.remove(20);
hs.display();
}