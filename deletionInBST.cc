#include<bits/stdc++.h>
#include"BST_Class.cc"
using namespace std;

/*------------------------taking input of BST by following BST terms-----------------------*/

Node<int> * insertBST(Node<int> * root,int data){
    if(root == NULL){
        root = new Node<int>(data);
        return root;
    }
    if(data>root->data){
        root->right = insertBST(root->right,data);
    }
    else{
        root->left = insertBST(root->left,data);
    }
    return root;
}

void takeInput(Node<int>* &root){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    while(data!=-1){
        root = insertBST(root,data);
        cout<<"Enter data"<<endl;
        cin>>data;
    }
}

/*---------------------------printing level wise------------------------------------*/
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


// finding minValue in BST
Node<int> * minVal(Node<int>*root){
    if(root->left == NULL){
        return root;
    }
    return minVal(root->left);
}

// finding maxValue in BST
Node<int> * maxVal(Node<int>*root){
    if(root->right == NULL){
        return root;
    }
    return maxVal(root->right);
}
// -1 using to show that the tree end here
// 10 9 20 15 21 -1
int main(){
    Node<int> * root = NULL;
    takeInput(root);
    printLevelWise(root);
    
    // cout<<"minValue "<< minVal(root)->data<<endl;
    // cout<<"maxValue "<<maxVal(root)->data<<endl;
}