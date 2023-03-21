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

  testTree.insert(std::make_pair(6, 8));
  testTree.print();
  testTree.insert(std::make_pair(3, 159));
  testTree.print();
  testTree.insert(std::make_pair(1, 9));
  testTree.print();
  testTree.insert(std::make_pair(10, 0x5a));
  testTree.print();
  testTree.insert(std::make_pair(5, 0xb));
  testTree.print();
  testTree.insert(std::make_pair(2, 4));
  testTree.print();
  /* testTree.insert(std::make_pair(4, 159));
  testTree.print(); */

  // EXPECT_TRUE(verifyAVL(testTree, std::set<uint16_t>({6, 3, 1, 10, 5, 2, 4})));



  return 0;
}
