#include<bits/stdc++.h>
#include"BST_Class.cc"
using namespace std;

/*------------------------taking input of BST by following BST terms-----------------------*/

Node<int> * insertBST(Node<int> * root,int data){
    if(root == NULL){
        root = new Node<int>(data);
        return root;
    }
    if(data > root->data){
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

/*---------------------------------Normal BST To Balanced BST----------------------------*/
/* A Balanced BST is defined as a BST, in which 
   the height of two subTrees of every node differ no more than 1*/

void solve(Node<int>* root,vector<int>&ans){
    if(root == NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

Node<int> * isBST(int s,int e,vector<int> ans){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node<int> * root = new Node<int>(ans[mid]);
    root->left = isBST(s,mid-1,ans);
    root->right = isBST(mid+1,e,ans);
    return root;
}

Node<int>* balancedBst(Node<int>* root) {
    // Write your code here.
    vector<int> ans;
    solve(root,ans);
    int s = 0;
    int e = ans.size()-1;
    return isBST(s,e,ans);
}



// -1 using to show that the tree end here
// 10 9 20 15 21 -1
int main(){
    Node<int> * root = NULL;
    takeInput(root);
    Node<int>* ans = balancedBst(root);


}