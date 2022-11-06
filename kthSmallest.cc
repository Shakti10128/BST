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
    if(root == NULL){
        return;
    }
    printLevelWise(root->left);
    cout<<root->data<<" ";
    printLevelWise(root->right);
}


/*------------------------kth Smallest element--------------------------*/

int solve(Node<int>*root,int&i,int k){
    if(root == NULL){
        return -1;
    }
    int left = solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i == k){
        return root->data;
    }
    return solve(root->right,i,k);
}

int kthSmallest(Node<int>* root, int k) {
    // Write your code here.
    int i = 0;
    return solve(root,i,k);
}



// -1 using to show that the tree end here
// 100 50 110 25 70 120 60 115 -1
int main(){
    Node<int> * root = NULL;
    takeInput(root);
    cout<<kthSmallest(root,2);
}