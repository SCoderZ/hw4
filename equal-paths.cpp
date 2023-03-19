#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int numOfChildren(Node * root) {
  int n = 0;
  if (root -> left != nullptr) {
    n++;
  }
  if (root -> right != nullptr) {
    n++;
  }
  return n;
}

// returns true if # of children of both nodes are positive or both 0
bool compareNodeChildren(Node *n1, Node *n2) {
  return ((numOfChildren(n1) > 0 && numOfChildren(n2) > 0) || (numOfChildren(n1) == 0 && numOfChildren(n2) == 0));
}


bool equalPaths(Node * root)
{
  if (root == nullptr) return true;
  if (numOfChildren(root) == 2) {
    if (!compareNodeChildren(root -> left, root -> right)) {
      return false;
    } else {
      return equalPaths(root -> left) && equalPaths(root -> right);
    }
  } else if (numOfChildren(root) == 1) {
    if (root -> left != nullptr) {
      equalPaths(root -> left);
    } else {
      equalPaths(root -> right);
    }
  } else if (numOfChildren(root) == 0) {
    return true;
  }
  return true;
}

