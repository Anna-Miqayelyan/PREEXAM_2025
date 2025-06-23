#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;
};
Node* front=nullptr;

void enqueue (int value, int prio){
Node * temp= new Node();
temp->data=value;
temp->priority=prio;
temp->next=nullptr;
if(front==nullptr||front->priority<prio){
    temp->next=front;
    front=temp;

}
else {
    Node* current=front;
    while(current->next!=nullptr && current->next->priority>=temp->priority){
       current=current->next;
    }
     temp->next=current->next;
        current->next=temp;
}

}

void dequeue(){
    if (front==nullptr) return;
    else {
        Node * temp=front;
        front=front->next;
        delete temp;
    }
}
int display()
{
    Node* temp=front;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" : "<<temp->priority<<endl;
        temp=temp->next;
    }
}

int main () {
    enqueue(1,4);
    enqueue(2,5);
    enqueue(3,0);
    enqueue(4,-7);
    enqueue(5,-1);
    enqueue(6,10);


    display();

}