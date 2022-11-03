#include<bits/stdc++.h>
#include"BST_Class.cc"
using namespace std;

// Take input level wise using queue
Node<int> * takeInput(){
    int data;
    cout<<"Enter the data of root"<<endl;
    cin>>data;
    Node<int> * root = new Node<int>(data);
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        Node<int> * front = q.front();
        q.pop();
        int leftdata;
        cout<<"Enter left node data of "<<front->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1){
            Node<int> * leftchild = new Node<int>(leftdata);
            front->left = leftchild;
            q.push(front->left);
        }
        int rightdata;
        cout<<"Enter right node data of "<<front->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1){
            Node<int> * rightchild = new Node<int>(rightdata);
            front->right = rightchild;
            q.push(front->right);
        }
    }
    return root;
}

// printing level wise
void printLevelWise(Node<int>*root){
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        Node<int> * front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}

int main(){
    Node<int> * root = takeInput();
    printLevelWise(root);
}