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



// Taking input as inOrder use -1 to indicate that your inOrder ends here
// 2 3 4 5 6 7 8 9 10 -1
// 1 3 6 8 -1
// Output -> 1 2 3 3 4 5 6 6 7 8 8 9 10
int main(){
    Node<int> * root1 = takeInput();
    Node<int> * root2 = takeInput();
    Node<int> * root = mergeBST(root1,root2);
    printLevelWise(root);
}