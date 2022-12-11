#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void changeTree(node * root) {
  if (root == NULL) 
    return;

  int child = 0;

  if (root -> left) {
    child += root -> left -> data;
  }

  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  changeTree(root -> left);
  changeTree(root -> right);

  int total = 0;
  if (root -> left) total += root -> left -> data;
  if (root -> right) total += root -> right -> data;
  if (root -> left or root -> right) root -> data = total;
}

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);
  
  vector < int > inOrder;
  inOrderTrav(root, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }

  return 0;
}

/*
    TC => O(N)
    SC => O(N) In the worst case( skewed tree).
*/