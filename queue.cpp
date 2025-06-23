#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* front=nullptr;
Node* rear=nullptr;


void enqueue(int value){
    Node* temp=new Node();
    temp->data=value;
    temp->next=nullptr;


    if (front==nullptr){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
        
    }

}
void dequeue(){
    if(front==nullptr){
        cout<<"Queue is empty!"<<endl;
    }
    else {
        Node* temp=new Node();
        temp=front;
        front=front->next;
        delete temp;
    }
}

void display(){
    Node* temp= new Node();
    temp=front;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    enqueue(2);
    enqueue(3);
    enqueue(5);
    enqueue(8);
    enqueue(13);

    display();

    dequeue();
    display();
        dequeue();
    display();
}
