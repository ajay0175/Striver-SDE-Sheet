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
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *curr = root;

        while(true) {
            if(curr -> val < p -> val and curr -> val < q -> val){
                curr = curr -> right;
            }
            else if(curr -> val > p -> val and curr -> val > q -> val) {
                curr = curr -> left;
            }
            else {
                break;
            }
        }

        return curr;
    }
};

int main() {

    struct TreeNode * root = new TreeNode(6);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(0);
    root -> left -> right = new TreeNode(4);
    root -> left -> right -> left = new TreeNode(3);
    root -> left -> right -> right = new TreeNode(5);
    root -> right = new TreeNode(8);
    root -> right -> left = new TreeNode(7);
    root -> right -> right = new TreeNode(9);

    Solution obj;

    TreeNode * p = new TreeNode(8);
    TreeNode * q = new TreeNode(7);
    TreeNode *ans = obj.lowestCommonAncestor(root, p, q);

    cout << ans -> val  << '\n';
    
    return 0;
}

/*
    TC => O(H) H is the Height of Tree.
    SC => O(1)
*/  