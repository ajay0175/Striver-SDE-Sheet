#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool solve(TreeNode *root, long l, long r)
    {
        if(!root)
            return true;
        
        if(root -> val <= l or root -> val >= r)
        {
            return false;    
        }
        
        return solve(root -> left, l, root -> val) and solve(root -> right, root -> val, r);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        
        return solve(root, LONG_MIN, LONG_MAX);
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
    bool flag = obj.isValidBST(root);

    if(flag) {
        cout << "It is valid BST" << '\n';
    }
    else {
        cout << "It is not a Valid BST" << '\n';
    }
    
    return 0;
}

/*
    TC => O(H)
    SC => O(H)
*/  