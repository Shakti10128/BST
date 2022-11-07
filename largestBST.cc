#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node<T> * left;
    Node<T> *right;

    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// taking input of binaryTree levelwise using queue
Node<int> * takeInputLevelWise(){
    int data;
    cout<<"Enter the root data"<<endl;
    cin>>data;
    Node<int>* root = new Node<int>(data);
    queue<Node<int> *>  pending;
    pending.push(root);
    while(pending.size()!=0){
        Node<int> * front = pending.front();
        pending.pop();
        cout<<"Enter the data of left child of "<<front->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            Node<int> * leftchild = new Node<int>(leftdata);
            front->left = leftchild;
            pending.push(leftchild);
        }

        cout<<"Enter the data of right child of "<<front->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            Node<int> * rightchild = new Node<int>(rightdata);
            front->right = rightchild;
            pending.push(rightchild);
        }
    }
    return root;

}

/*------------------------largest BST in Binary Tree--------------------------*/
class info{
  public:
    int min;
    int max;
    bool isBST;
    int size;
};

info solve(Node<int>*root,int &maxsize){
    if(root == NULL){
        return {INT_MAX,INT_MIN,true,0};
    }
    info left = solve(root->left,maxsize);
    info right = solve(root->right,maxsize);
    
    info curr;
    curr.size = left.size + right.size + 1;
    curr.min = min(root->data,left.min);
    curr.max = max(root->data,right.max);
    if(left.isBST && right.isBST && (root->data > left.max && root->data < right.min)){
        curr.isBST = true;
    }
    else{
        curr.isBST = false;
    }
    if(curr.isBST){
        maxsize = max(maxsize,curr.size);
    }
    return curr; 
}


int largestBST(Node<int>* root) 
{
    // Write your code here.
    int maxsize = 0;
    info temp = solve(root,maxsize);
    return maxsize;
    
}


// Taking input as inOrder use -1 to indicate that your inOrder ends here
// 5 2 4 1 3 -1 -1 -1 -1 -1 -1 
int main(){
    Node<int> * root = takeInputLevelWise();
    int ans = largestBST(root);
    cout<<ans<<endl;
}