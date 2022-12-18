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
    int Predecessor(TreeNode *root, int key){
        TreeNode *predecessor = NULL;
        while(root) {
            if(key > root -> val){
                predecessor = root;
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        } 

        return predecessor -> val;
    }

    int Successor(TreeNode *root, int key) {
        TreeNode *successor = NULL;

        while(root) {
            if(key >= root -> val){
                root = root -> right;
            }
            else{
                successor = root;
                root = root -> left;
            }
        }

        return successor -> val; 
    }
};

int main() {

    struct TreeNode * root = new TreeNode(15);
    root -> left = new TreeNode(10);
    root -> left -> left = new TreeNode(8);
    root -> left -> right = new TreeNode(12);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(16);
    root -> right -> right = new TreeNode(25);

    Solution obj;
    int key = 10;
    pair<int, int> ans = {obj.Predecessor(root, key), obj.Successor(root, key)};

    cout << ans.first << " " << ans.second << '\n';
    
    return 0;
}

/*
    TC => O(H) H is the Height of Tree.
    SC => O(1)
*/  