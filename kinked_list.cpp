#include <iostream>
using namespace std;

struct Node{
int data;
Node* next;


};
void insert (Node*& root,int value){
  
    Node* temp=new Node();
    temp->data=value;
    temp->next=root;
    root=temp;



}
void insertFromTail(Node*& root, int value){
    
    while(root->next!=nullptr)root = root->next;
    root->next->data=value;
}
void print(Node* root){
  
    while(root!=nullptr){
    cout<<root->data<<" -> ";
    root=root->next;
}

}
int main(){
    Node* root=nullptr;
    insert(root,4);
      insert(root,7);
        insert(root,9);
          insert(root,10);
    insertFromTail(root,65);

    print(root);
    
}