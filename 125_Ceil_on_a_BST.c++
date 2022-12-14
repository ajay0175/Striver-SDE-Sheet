#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
public:
    int findCeil(TreeNode *root, int key){
        int ceil = -1;
        
        while(root) {
            if(key == root -> data) {
                ceil = root -> data;
                return ceil;
            }
            
            if(key > root -> data) {
                root = root -> right;
            }
            else {
                ceil = root -> data;
                root = root -> left;
            }
        }
        
        return ceil;
    }
};

int main() {

    struct TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    Solution obj;
    
    
    return 0;
}

/*
    TC => O(H) H is the Height of Tree.
    SC => O(1)
*/  