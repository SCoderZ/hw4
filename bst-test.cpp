#include <iostream>
#include <map>
#include "avlbst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
  AVLTree<int, double> bst;
  bst.insert(std::make_pair(3, 1.0));
  bst.print();
  bst.insert(std::make_pair(4, 1.0));
  bst.print();
  bst.insert(std::make_pair(2, 1.0));
  bst.print();
  bst.insert(std::make_pair(1, 1.0));
  bst.print();
  bst.remove(4);
  bst.print();

  // EXPECT_TRUE(verifyAVL(bst, {1, 2, 3}));



  return 0;
}
