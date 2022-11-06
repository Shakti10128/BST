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

/*-----------------------------------merge Two BST--------------------------------------*/

void inOrder(Node<int>* root,vector<int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}
vector<int> mergeTwoSortedArray(vector<int> &a,vector<int> &b){
    vector<int> temp(a.size() + b.size());
    int i = 0;
    int j = 0;
    int index = 0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            temp[index++] = a[i];
            i++;
        }
        else{
            temp[index++] = b[j];
            j++;
        }
    }
    while(i<a.size()){
        temp[index++] = a[i];
        i++;
    }
    while(j<b.size()){
        temp[index++] = b[j];
        j++;
    }
    return temp;
}

Node<int> * mergeTwoBST(int s,int e,vector<int> temp){
//     base case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node<int> * root = new Node<int>(temp[mid]);
    root->left = mergeTwoBST(s,mid-1,temp);
    root->right = mergeTwoBST(mid+1,e,temp);
    return root;
}

Node<int> *mergeBST(Node<int> *root1, Node<int> *root2){
    // Write your code here.
    vector<int> a,b;
    inOrder(root1,a);
    inOrder(root2,b);
    vector<int> temp = mergeTwoSortedArray(a,b);
    int s = 0;
    int e = temp.size()-1;
    return mergeTwoBST(s,e,temp);
}



// -1 using to show that the tree end here
// 4 2 7 5 1 8 10 -1 
// 5 1 7 3 6 8 2 -1
//Output-> 1 1 2 2 3 4 5 5 6 7 7 8 8 10
int main(){
    Node<int> * root1 = NULL;
    takeInput(root1);
    Node<int> * root2 = NULL;
    takeInput(root2);
    Node<int> * root = mergeBST(root1,root2);
    printLevelWise(root);
}