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


// Taking input as inOrder use -1 to indicate that your inOrder ends here
// 2 3 4 5 6 7 8 9 10 -1
int main(){
    Node<int> * root = takeInput();
    Node<int>* ans = deleteFromBST(root,120);
    printLevelWise(ans);

    // cout<<"minValue "<< minVal(root)->data<<endl;
    // cout<<"maxValue "<<maxVal(root)->data<<endl;
}