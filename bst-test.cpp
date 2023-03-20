#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    /* BinarySearchTree<char,int> bt;
    bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('b',2));
    
    cout << "Binary Search Tree contents:" << endl;
    for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    if(bt.find('b') != bt.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    bt.remove('b');

    // AVL Tree Tests
    AVLTree<char,int> at;
    at.insert(std::make_pair('a',1));
    at.insert(std::make_pair('b',2));

    cout << "\nAVLTree contents:" << endl;
    for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    if(at.find('b') != at.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    at.remove('b'); */
 /* BinarySearchTree<uint16_t, uint16_t> testTree;

        testTree.insert(std::make_pair(5, 8));
        testTree.print();
        testTree.insert(std::make_pair(3, 159));
        testTree.print();
        testTree.insert(std::make_pair(1, 9));
        testTree.print();
        testTree.insert(std::make_pair(10, 0x5a));
        testTree.print();
        testTree.insert(std::make_pair(15, 0xb));
        testTree.print();
        testTree.insert(std::make_pair(2, 4));
        testTree.print();
        testTree.insert(std::make_pair(4, 159));
        testTree.print(); */

 BinarySearchTree<int, double> bst;
        bst.insert(std::make_pair(2, 1.0));
        bst.insert(std::make_pair(1, 1.0));
        bst.insert(std::make_pair(3, 1.0));
        bst.remove(2);

        // EXPECT_TRUE(verifyBST(bst, {1, 3}));

        // EXPECT_TRUE(verifyBST(bst, {2, 6, 4}));

        // EXPECT_TRUE(verifyBST(testTree, std::set<uint16_t>({5, 3, 1, 10, 15, 2, 4})));

  // bst.print();


  return 0;
}
