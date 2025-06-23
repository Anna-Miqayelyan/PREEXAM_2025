#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

};
Node* top =nullptr;
void push(int data ){
    Node* newnode=new Node();
    newnode->data=data;
    newnode->next=top;
    top=newnode;

}
void print(){
    Node* temp=new Node();
    temp=top;
    while(temp!=nullptr){
      cout<<temp->data<<' ';
      temp=temp->next;
    }
}
void pop(){
    Node* temp=new Node();
    cout<<endl<<"Top is: "<<top->data<<endl;
       temp=top;
       top=top->next;
       delete temp;
       

}
bool isempty(){
    
    return top==nullptr;
}
void clear(){
    while (top!=nullptr){
        pop();
    }
}
int main(){
    push(4);
    push(5);
    push(7);
    push(8);
    push(1);

    print();
    pop();
        print();
         pop();
        print();

        cout<<endl<<isempty()<<endl;

        clear();

         print();

        cout<<endl<<isempty()<<endl;

}