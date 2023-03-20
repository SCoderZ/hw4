#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
  BinarySearchTree<std::string, std::string> testTree;
  cout << testTree.isBalanced() << endl;


  return 0;
}
