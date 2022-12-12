#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  struct TreeNode * left, * right;
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL and root -> val != val) {
            root = val < root -> val ? root -> left : root -> right;
        }
        return root;
    }
};

struct TreeNode * newNode(int data) {
  struct TreeNode * Node = (struct TreeNode * ) malloc(sizeof(struct TreeNode));
  Node -> val = data;
  Node -> left = NULL;
  Node -> right = NULL;

  return (Node);
}

int main() {
    struct TreeNode * root = newNode(4);
    root -> left = newNode(2);
    root -> left -> left = newNode(1);
    root -> left -> right = newNode(3);
    root -> right = newNode(7);

    Solution obj;
    int key = 2;
    obj.searchBST(root, key);

    return 0;
}

/*
    TC => O(LOG N)
    SC => O(LOG N)
*/