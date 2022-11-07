#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

unordered_map<int, int> mp;

node* constructTree(vector<int> &inOrder, int inStart, int inEnd, vector<int> &postOrder, int postStart, int postEnd) {
        if(inStart > inEnd or postStart > postEnd) {
            return NULL;
        }    
        
        int root = postOrder[postEnd];
        node *tempNode = newNode(root);
        int rootPos = mp[root], x = inStart;
        
        tempNode -> left = constructTree(inOrder, inStart, rootPos - 1, postOrder, postStart, postStart  +(rootPos - x) - 1);
        
        tempNode -> right = constructTree(inOrder, rootPos + 1, inEnd, postOrder, postStart + (rootPos - x), postEnd - 1);
        
        return tempNode;
    }

node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd);
}

vector<int> levelOrder(node* root) {
        vector<int> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<node*> q; 
        q.push(root); 
        
        while(!q.empty()) {
           
            node *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            ans.push_back(temp -> data); 
        }
        return ans; 
}

int main() {

  vector<int> postorder{9,15,7,20,3};
  vector<int> inorder{ 9,3,15,20,7};
  node * root = buildTree(postorder, inorder);
  vector<int> ans = levelOrder(root);

  cout << "The element of binary tree is: ";
  for(auto &e : ans) {
    cout << e << " ";
  }

  return 0;
}

/*
  TC => O(N)
  SC => O(N)
*/