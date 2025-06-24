#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    unordered_map<char,Node*> next;
    bool isEnd;
    Node(){
        isEnd=false;
    }
};
class Trie{
    Node* root;
public:
Trie(){
    root=new Node();
}

void Insert(const string& word){
    Node* curr=root;
    for(char ch:word){
        if(!curr->next[ch])
        curr->next[ch]=new Node();
        curr=curr->next[ch];
    }
    curr->isEnd=true;
}
bool search(const string& word){
    Node* curr=root;
    for(char ch:word){
        if(!curr->next.count(ch)) return false;
        curr=curr->next[ch];
    }
    return curr->isEnd;
}
void remove(const string& word){
    Node* curr=root;
    for(char ch:word){
        if(!curr->next.count(ch))
        return;
         curr=curr->next[ch];

    }
    curr->isEnd=false;


}
};

int main() {
    Trie trie;
    trie.Insert("cat");
    trie.Insert("dog");

    cout << "Search cat: " << trie.search("cat") << endl; // 1
    cout << "Search dog: " << trie.search("dog") << endl; // 1
    cout << "Search cow: " << trie.search("cow") << endl; // 0

    trie.remove("cat");
    cout << "Search cat after delete: " << trie.search("cat") << endl; // 0

    return 0;
}
