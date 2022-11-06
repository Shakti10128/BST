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

/*-----------------------------------merge Two BST--------------------------------------*/

void inOrder(TreeNode<int>* root,vector<int> &in){
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

TreeNode<int> * mergeTwoBST(int s,int e,vector<int> temp){
//     base case
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int> * root = new TreeNode<int>(temp[mid]);
    root->left = mergeTwoBST(s,mid-1,temp);
    root->right = mergeTwoBST(mid+1,e,temp);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
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
// 4 2 7 -1 3 -1 -1 -1 -1  
// 5 1 7 -1 -1 -1 -1
int main(){
    Node<int> * root1 = NULL;
    takeInput(root1);
    Node<int> * root2 = NULL;
    takeInput(root2);
}