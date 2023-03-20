#include <iostream>
#include <map>
#include "avlbst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
  // BinarySearchTree<std::string, std::string> testTree;
  // cout << testTree.isBalanced() << endl;

  AVLTree<uint16_t, uint16_t> testTree;

  testTree.insert(std::make_pair(2, 9));
  testTree.insert(std::make_pair(1, 8));
  testTree.insert(std::make_pair(0, 159));


  return 0;
}
