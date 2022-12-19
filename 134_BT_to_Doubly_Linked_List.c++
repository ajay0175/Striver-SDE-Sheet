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

void inOrder(TreeNode *root, vector<int> &v) {
    if (!root)      
    {
        return;
    }

    inOrder(root -> left, v);
    v.emplace_back(root -> val);
    inOrder(root -> right, v);
}

TreeNode* BTtoDLL(TreeNode* root) {
    std::vector<int> v;
    inOrder(root, v);

    TreeNode *head = new TreeNode(-1);
    TreeNode *curr = head;
    TreeNode *prev = NULL;

    for(auto &val : v) {
        TreeNode *temp = new TreeNode(val);
        curr -> right = temp;
        curr -> left = prev;
        prev = curr;
        curr = curr -> right;
    }

    curr -> right = NULL;
    return head -> right;
}

int main() {

    struct TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(5);

    TreeNode *node = BTtoDLL(root);
     
    return 0;
}

/*
    TC => O(N)
    SC => O(N)
*/