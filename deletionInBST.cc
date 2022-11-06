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


Node<int>* deleteFromBST(Node<int>*root,int x){
    if(root == NULL){
        return root;
    }
    if(root->data == x){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child

        // for left child
        if(root->left!=NULL && root->right == NULL){
            Node<int>* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right!=NULL){
            Node<int> * temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data < x){
        root->right = deleteFromBST(root->right,x);
        return root;
    }
    else{
        root->left = deleteFromBST(root->left,x);
        return root;
    }
    return root;
}


// -1 using to show that the tree end here
// 100 50 110 25 70 120 60 115 -1
int main(){
    Node<int> * root = NULL;
    takeInput(root);
    Node<int>* ans = deleteFromBST(root,120);
    printLevelWise(ans);

    // cout<<"minValue "<< minVal(root)->data<<endl;
    // cout<<"maxValue "<<maxVal(root)->data<<endl;
}