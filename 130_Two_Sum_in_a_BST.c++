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

class BSTIterator {
    stack<TreeNode*> myStack;
    //reverse = true => beftor [decreasing order]
    // reverse = false => next [increasing order]

    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *topNode = myStack.top();
        myStack.pop();

        if(!reverse) {
            pushAll(topNode -> right);
        }
        else{
            pushAll(topNode -> left);
        }

        return topNode -> val;
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            myStack.emplace(node);

            if(reverse) {
                node = node -> right;
            }
            else{
                node = node -> left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }

        BSTIterator l(root, false); // Increasing order for next
        BSTIterator r(root, true); // Decreasing order for before

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k) {
                return true;
            }
            else if(i + j < k) {
                i = l.next();
            }
            else{
                j = r.next();
            }
        }

        return false;
    }
};

int main() {

    struct TreeNode * root = new TreeNode(5);
    root -> left = new TreeNode(3);
    root -> left -> left = new TreeNode(2);
    root -> left -> right = new TreeNode(4);
    root -> right = new TreeNode(6);
    root -> right -> right = new TreeNode(7);

    Solution obj;
    int key = 9;

    bool target = obj.findTarget(root, key);

    if(target) {
        cout << "Target sum is Present" << '\n';
    }
    else {
        cout << "Target sum is not Present" << '\n';
    }
    
    return 0;
}

/*
    TC => O(N) 
    SC => O(H) H is the Height of Tree.
*/  