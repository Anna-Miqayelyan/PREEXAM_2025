#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node (int val){
        data=val;
        left=right=nullptr;
        height=1;
    }
};
int getHeight(Node* node){
    return node?node->height:0;
}
int getBalance(Node* node){
    return node? getHeight(node->left)-getHeight(node->right):0;
}
int updateHeight(Node* node){
  return   node->height=1+max(getHeight(node->left),getHeight(node->right));
}
Node* rotateRight(Node* y){
    Node* x=y->left;
    Node* T2=x->right;

    x->right=y;
    y->left=T2;
    updateHeight(y);
    updateHeight(x);

    return x;
}
Node* rotateLeft(Node* x){
    Node* y=x->right;
    Node* T2=x->left;
    y->left=x;
    x->right=T2;

    updateHeight(x);
    updateHeight(y);
    return y;

}
Node* insert(Node* root,int key){
if(!root) return new Node(key);

if(key<root->data)
  root->left=insert(root->left,key);
else if (key>root->data)
  root->right=insert(root->right,key);
else return root;

updateHeight(root);

int balance=getBalance(root);
if(balance>1&&key<root->left->data)
   return rotateRight(root);
else if(balance>1&& key>root->left->data){
    root->left=rotateLeft(root->left);
    return rotateRight(root);
}
else if(balance<-1&&key>root->right->data)
return rotateLeft(root);
else if(balance<-1 && key<root->right->data){
    root->right=rotateRight(root->right);
return rotateRight(root);
}
return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;
    int values[] = {10, 20, 30, 40, 50, 25};

    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder  AVL Tree: ";
    inorder(root);  
    return 0;
}