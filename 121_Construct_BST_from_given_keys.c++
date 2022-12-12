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
    TreeNode *createBST(vector<int> &nums, int left, int right) {
        if(left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;

        TreeNode *temp = new TreeNode(nums[mid]);

        temp -> left = createBST(nums, left, mid - 1);
        temp -> right = createBST(nums, mid + 1, right);

        return temp;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size() - 1);
    }
};

void inOrderTrav(TreeNode * curr, vector <int> & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> val);
  inOrderTrav(curr -> right, inOrder);
}

int main() {
    
    vector<int> nums = {-10,-3,0,5,9};

    Solution obj;

    struct TreeNode *root = obj.sortedArrayToBST(nums);

    vector <int> inOrder;
    inOrderTrav(root, inOrder);

    cout << "The inOrder Traversal is : ";
    for (int i = 0; i < inOrder.size(); i++) {
        cout << inOrder[i] << " ";
    }
    
  return 0;
}
 
 /*
    TC => O(LOG N)
    SC => O(H)
*/