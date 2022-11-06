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
// if interviewer say to you that solve this question in O(h) space complexity then use this approach


// Converting Tree into Sorting Doubly Linked list
void convertSortedLL(Node<int>*root,Node<int>* & head){
    // base case
    if(root == NULL){
        return;
    }
    convertSortedLL(root->right,head);
    root->right = head;
    if(head!=NULL){
        head->left = root;
    }
    head = root;
    convertSortedLL(root->left,head);
}

// Merging two sorting linked list
Node<int>* mergeTwoSortedLL(Node<int>* head1,Node<int>*head2){
    Node<int> * head = NULL;
    Node<int>* tail = NULL;
    // merging two dobuly linked list
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){
            // checking weither the head NULL or not
            if(head== NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                // head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            // checking weither the head NULL or not
            if(head==NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                // head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    // confirming weither the head1 NULL or not, if not then merge into final linked list
    while(head1!=NULL){
        tail->right = head1;
        // head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    // confirming weither the head2 NULL or not, if not then merge into final linked list
    while(head2!=NULL){
        tail->right = head2;
        // head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return  head;
}

// finding the length of SortedDLL
int findLength(Node<int>* head){
    Node<int>* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->right;
    }
    return len;
}

// converting SortedLLToBST
Node<int>* SortedLLToBST(Node<int>* &head,int length){
    if(length<= 0 || head == NULL){
        return NULL;
    }
    Node<int>* left = SortedLLToBST(head,length/2);
    Node<int> * root = head;
    root->left = left;
    head = head->right;
    root->right = SortedLLToBST(head,length-length/2-1);
    return root;
}



/*-----------------------------------merge Two BST--------------------------------------*/
// in this approach we are using extra space by help of vector

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
// 2 4 5 7 9 10 -1
// 1 3 6 8 -1
// Output -> 1 2 3 3 4 5 6 6 7 8 8 9 10
int main(){
    Node<int> * root1 = takeInput();
    Node<int> * root2 = takeInput();

    /*-----------in this approach we are using extra space by help of vector------------*/
    // Node<int> * root = mergeBST(root1,root2);
    // printLevelWise(root);



    /*--------if interviewer say to you that solve this question in O(h) space complexity then use this approach---------*/
    Node<int> * head1 = NULL;
    Node<int> * head2 = NULL;
    convertSortedLL(root1,head1);
    convertSortedLL(root2,head2);
    Node<int> * head = mergeTwoSortedLL(head1,head2);
    int length = findLength(head);
    Node<int> * root = SortedLLToBST(head,length);
    printLevelWise(root);
}