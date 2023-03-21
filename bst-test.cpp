#include <iostream>
#include <map>
#include "avlbst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
  /* AVLTree<int, double> bst;
  bst.insert(std::make_pair(3, 1.0));
  bst.print();
  bst.insert(std::make_pair(4, 1.0));
  bst.print();
  bst.insert(std::make_pair(2, 1.0));
  bst.print();
  bst.insert(std::make_pair(1, 1.0));
  bst.print();
  bst.remove(4);
  bst.print(); */
AVLTree<int, double> bst;
        bst.insert(std::make_pair(2, 1.0));
  bst.print();
        bst.insert(std::make_pair(1, 1.0));
  bst.print();
        bst.insert(std::make_pair(3, 1.0));
  bst.print();
        bst.remove(2);
  bst.print();

        /* EXPECT_TRUE(verifyAVL(bst, {1, 3}));

        // predecessor, 1, should be promoted
        ASSERT_NE((void*)nullptr, (void*)bst.root_);
        EXPECT_EQ(1, bst.root_->getKey());

        ASSERT_NE((void*)nullptr, (void*)bst.root_->getRight());
        EXPECT_EQ(3, bst.root_->getRight()->getKey());

        ASSERT_EQ((void*)nullptr, (void*)bst.root_->getLeft()); */

  // EXPECT_TRUE(verifyAVL(bst, {1, 2, 3}));



  return 0;
}
