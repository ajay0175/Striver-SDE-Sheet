#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * left, * right, * next;
};

class Solution {
public:
    Node* connect(Node* root) {
       queue<Node*> q;
        if (!root)
            return NULL;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if (i == size - 1)
                    node->next = nullptr;
                else
                    node->next = q.front();
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};

struct Node * newNode(int data) {
  struct Node * Node = (struct Node * ) malloc(sizeof(struct Node));
  Node -> data = data;
  Node -> left = NULL;
  Node -> right = NULL;
  Node -> next = NULL;

  return (Node);
}

int main() {

    struct Node * root = newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right = newNode(3);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);

    Solution obj;
    obj.connect(root);

    cout << root -> data << "  ->  " << (root -> next ? root -> next -> data : -1) << endl;

    cout << root -> left -> data << "  ->  " << (root -> left -> next ? root -> left -> next -> data : -1) << endl;

    cout << root -> right -> data << "  ->  " << (root -> right -> next ? root -> right ->right -> next -> data : -1) << endl;

    cout <<  root -> left -> left -> data << "  ->  " << (root -> left -> left -> next ? root -> left -> left -> next -> data : -1) << endl;

    cout <<  root -> left -> right -> data << "  ->  " << (root -> left -> right -> next ? root -> left -> right -> next -> data : -1) << endl;

    cout <<  root -> right -> left -> data << "  ->  " << (root -> right -> left -> next ? root -> right -> left -> next -> data : -1) << endl;
    
    cout <<  root -> right -> right -> data << "  ->  " << (root -> right -> right -> next ? root -> right -> right -> next -> data : -1) << endl;
    
    return 0;
}

/*
    TC -> O(N)
    SC -> O(N)
*/