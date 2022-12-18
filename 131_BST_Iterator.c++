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
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *topNode = myStack.top();
        myStack.pop();

        pushAll(topNode -> right);

        return topNode -> val;
    }

private:
    void pushAll(TreeNode *node) {
        while(node != NULL) {
            myStack.emplace(node);

            node = node -> left;
        }
    }
};

int main() {

    struct TreeNode * root = new TreeNode(7);
    root -> left = new TreeNode(3);
    root -> right = new TreeNode(15);
    root -> right -> left = new TreeNode(9);
    root -> right -> right = new TreeNode(20);

    BSTIterator inorder(root);

    int a = inorder.next();
    int b = inorder.next();
    bool b1 = inorder.hasNext();
    string b2 = (b1) ? "true" : "false";
    int c = inorder.next();
    bool c1 = inorder.hasNext();
    string c2 = (c1) ? "true" : "false";
    int d = inorder.next();
    bool d1 = inorder.hasNext();
    string d2 = (d1) ? "true" : "false";
    int e = inorder.next();
    bool e1 = inorder.hasNext();
    string e2 = (e1) ? "true" : "false";

    cout << a << " " << b << " " << b2 << " " << c << " " << c2 << " " << d <<
        " " << d2 << " " << e << " " << e2 << '\n';
    
    return 0;
}

/*
    TC => O(1) 
    SC => O(H) H is the Height of Tree.
*/ 