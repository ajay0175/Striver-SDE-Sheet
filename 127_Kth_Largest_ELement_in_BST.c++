#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertBST(node *root,int val) {
    if(root == NULL) {
        return new node(val);
    }

    if(val < root -> data) {
        root -> left = insertBST(root -> left, val);
    } 
    else {
        root->right = insertBST(root -> right, val);
    }

    return root;
}

node* kthlargest(node* root, int  &k) {
    if(root == NULL){
        return NULL;
    }
    
    node* right = kthlargest(root -> right, k);

    if(right != NULL) {
        return right;
    }

    k--;
    
    if(k == 0) {
        return root;
    }
    
    return kthlargest(root -> left,k);
}

int main() {
    
    int arr[] = {10,40,45,20,25,30,50};
    
    int k = 3;
    node* root = NULL;

    for(int i = 0; i < 7; i++) {
        root = insertBST(root, arr[i]);
    }

    cout << "\n";

    node* large = kthlargest(root, k);
    
    if(large == NULL) {
        cout << "Invalid input" << "\n";
    }
    else {
     cout<<"kth largest element is  "<<large -> data<<"\n";
    }
}

/*
    TC => O(MIN(K, N))
    SC => O(MIN(K, N))
*/