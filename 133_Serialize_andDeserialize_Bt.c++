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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }

        string s = "";
        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()) {
            TreeNode *currNode = q.front();
            q.pop();

            if(currNode == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(currNode -> val) + ',');
            }

            if(currNode != NULL) {
                q.emplace(currNode -> left);
                q.emplace(currNode -> right);
            }
        }

        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) {
            return NULL;
        }   

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.emplace(root);

        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node -> left = NULL;
            }
            else {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node -> left = leftNode;
                q.emplace(leftNode); 
            }

            getline(s, str, ',');
            if(str == "#") {
                node -> right = NULL;
            }
            else {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node -> right = rightNode;
                q.emplace(rightNode); 
            }
        }

        return root;
    }
};

int main() {

    // Here we are Using Level order Technique 
    //and we can solve the question using any Traversal technique
    //like inorder, preorder, postorder, morris and etc.

    struct TreeNode * root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(4);
    root -> right -> right = new TreeNode(5);

    Codec obj;

    string s = obj.serialize(root);
    TreeNode *ans = obj.deserialize(s);

    //The Output is going to be same as Input
     
    return 0;
}

/*
    TC => O(N) 
    SC => O(N)
*/ 