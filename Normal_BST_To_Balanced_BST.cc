#include<bits/stdc++.h>
#include"BST_Class.cc"
using namespace std;

/*------------------------taking input of BST as inOrder-----------------------*/

Node<int> * BST(int s,int e,vector<int> ans){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node<int> * root = new Node<int>(ans[mid]);
    root->left = BST(s,mid-1,ans);
    root->right = BST(mid+1,e,ans);
    return root;
}

Node<int>* takeInput(){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    vector<int> ans;
    while(data!=-1){
        ans.push_back(data);
        cin>>data;
    }
    int s = 0;
    int e = ans.size()-1;
    return BST(s,e,ans);
}

/*---------------------------printing BST ------------------------------------*/
// We all know that the inOrder of BST is sorted
void printLevelWise(Node<int>*root){
    if(root == NULL){
        return;
    }
    printLevelWise(root->left);
    cout<<root->data<<" ";
    printLevelWise(root->right);
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



// Taking input as inOrder use -1 to indicate that your inOrder ends here
// 2 3 4 5 6 7 8 9 10 
int main(){
    Node<int> * root = takeInput();
    Node<int>* ans = balancedBst(root);


}