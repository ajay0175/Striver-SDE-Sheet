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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

    TreeNode *build(vector<int> &preorder, int &nodeIdx, int bound) {
        if(nodeIdx == preorder.size() or preorder[nodeIdx] > bound) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[nodeIdx++]);
        root -> left = build(preorder, nodeIdx, root -> val);
        root -> right = build(preorder, nodeIdx, bound);

        return root;
    }
};

vector<int> levelOrder(TreeNode* root) {
    vector<int> ans; 
    
    if(root == NULL) 
        return ans; 
        
    queue<TreeNode*> q; 
    q.push(root); 
    
    while(!q.empty()) {
        
        TreeNode *temp = q.front(); 
        q.pop(); 
        
        if(temp->left != NULL) 
            q.push(temp->left); 
        if(temp->right != NULL) 
            q.push(temp->right); 
            
        ans.push_back(temp -> val); 
    }
    return ans; 
}

int main() {
    
    vector<int> preoder = {8,5,1,7,10,12};

    Solution obj;
    TreeNode *root = obj.bstFromPreorder(preoder);
    vector<int> ans = levelOrder(root);

    cout << "The element of binary search tree is: ";
    for(auto &e : ans) {
        cout << e << " ";
    }

  return 0;
}
 
  /*
    TC => O(LOG N)
    SC => O(H)
*/