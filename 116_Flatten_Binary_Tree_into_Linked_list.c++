#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

class Solution {
  node * prev = NULL;
  public:
   void flatten1(node * root) {
      if (root == NULL) return;

      flatten1(root -> right);
      flatten1(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

   void flatten2(node* root) {
        node* cur = root;
		while (cur)
		{
			if(cur->left)
			{
				node* pre = cur->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }



};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(5);
  root -> right -> right = newNode(6);
  root -> right -> right -> left = newNode(7);

  Solution obj;

  obj.flatten1(root);
  while(root -> right != NULL)
  {
      cout << root -> data << "->";
      root= root -> right;
  }

  cout << root -> data << '\n';

  obj.flatten2(root);
  while(root -> right != NULL)
  {
      cout << root -> data <<"->";
      root = root -> right;
  }
  cout << root -> data;
  
  return 0;
}

/*
    flatten1
    TC => O(N)
    SC => O(N)

    flatten2
    TC => O(N)
    SC => O(N)
*/