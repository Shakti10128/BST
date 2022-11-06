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

/*---------------------------------Flatten BST To A Sorted List----------------------------*/


void solve(Node<int>* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

Node<int>* flatten(Node<int>* root)
{
    // Write your code here
    vector<int> ans;
    solve(root,ans);
    int size = ans.size();
    Node<int> * newRoot = new Node<int>(ans[0]);
    Node<int> * curr = newRoot;
    for(int i = 1;i<size;i++){
        Node<int> * temp = new Node<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    return newRoot;
}



// -1 using to show that the tree end here
// 10 9 20 15 21 -1
int main(){
    Node<int> * root = NULL;
    takeInput(root);
    Node<int> * ans = flatten(root);
    cout<<"linked list is printing"<<endl;
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->right;
    }
}