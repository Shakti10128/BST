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



// Taking input as inOrder use -1 to indicate that your inOrder ends here
// 2 3 4 5 6 7 8 9 10 -1
int main(){
    Node<int> * root = takeInput();
    cout<<kthSmallest(root,2);
}