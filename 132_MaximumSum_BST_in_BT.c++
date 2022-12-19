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

int ans;
class Node {
public:
    bool bst;                    //to check if tree is bst
    int maxValue, minValue, maxSum;

    Node(){
        bst = true;
        maxValue = INT_MIN;      //max value in a tree
        minValue = INT_MAX;      //min value in a tree
        maxSum = 0;              //Current Maximum sum
    }
};

class Solution {
public:
    Node calcSum(TreeNode* root){
        if (root == NULL){
            return Node();
        }
        Node bt;
        Node btLeft = calcSum(root -> left);             //recursive call for left sub-tree
        Node btRight = calcSum(root -> right);           //recursive call for right sub-tree
        
        //if sub-tree including this node is bst
        if (btLeft.bst == true && btRight.bst == true && root -> val > btLeft.maxValue && root -> val < btRight.minValue){
            bt.bst = true;                       //current tree is a bst
            bt.maxSum = btLeft.maxSum + btRight.maxSum + root -> val;          
            bt.minValue  = min(root -> val, btLeft.minValue);
            bt.maxValue = max(root -> val, btRight.maxValue);
        }
        //if current tree is not a bst
        else {
            bt.bst = false;
            bt.maxSum = max(btLeft.maxSum, btRight.maxSum);
        }
        
        ans = max(ans, bt.maxSum);
        return bt;
    }

    int maxSumBST(TreeNode* root){
        ans = 0;
        calcSum(root);
        return ans;
    }
};

int main() {

    struct TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(4);
    root -> left -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(4);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(2);
    root -> right -> right = new TreeNode(5);
    root -> right -> right -> left = new TreeNode(4);
    root -> right -> right -> right = new TreeNode(6);

    Solution obj;
    
    obj.maxSumBST(root);

    cout << "Maximum Sum is " << ans << '\n';
     
    return 0;
}

/*
    TC => O(N) 
    SC => O(H) H is of the Tree.
*/ 