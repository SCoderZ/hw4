#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);
    void rotateRight(AVLNode<Key, Value>* z);
    void rotateLeft(AVLNode<Key, Value>* z);
    bool isRightChild(AVLNode<Key, Value>* n);
    void insertFix(AVLNode<Key, Value>* p, AVLNode<Key, Value>* n);
    void removeFix(AVLNode<Key, Value>* n, int diff);

    // Add helper functions here


};

template<class Key, class Value>
void AVLTree<Key, Value>::removeFix (AVLNode<Key, Value>* n, int diff) {
  if (n == nullptr) return;
  AVLNode<Key, Value>* p = n -> getParent();

  if (p != nullptr) {
    int ndiff;
    if (!isRightChild(n)) {
      ndiff = 1;
    } else {
      ndiff = -1;
    }
    if (diff == -1) {
      if (n -> getBalance() + diff == -2) {
        AVLNode<Key, Value>* c = n -> getLeft();
        if (c -> getBalance() == -1) {
          rotateRight(n);
          n -> setBalance(0);
          c -> setBalance(0);
          removeFix(p, ndiff);
        } else if (c -> getBalance() == 0) {
          rotateRight(n);
          n -> setBalance(-1);
          c -> setBalance(1);
        } else if (c -> getBalance() == 1) {
          AVLNode<Key, Value>* g = c -> getRight();
          rotateLeft(c);
          rotateRight(n);
          if (g -> getBalance() == 1) {
            n -> setBalance(0);
            c -> setBalance(-1);
            g -> setBalance(0);
          } else if (g -> getBalance() == 0) {
            n -> setBalance(0);
            c -> setBalance(0);
            g -> setBalance(0);
          } else if (g -> getBalance() == -1) {
            n -> setBalance(1);
            c -> setBalance(0);
            g -> setBalance(0);
          }
          removeFix(p, ndiff);
        }
      } else if (n -> getBalance() + diff == -1) {
        n -> setBalance(-1);
      } else if (n -> getBalance() + diff == 0) {
        n -> setBalance(0);
        removeFix(p, ndiff);
      }
    } else if (diff == 1) {
      if (n -> getBalance() + diff == +2) {
        AVLNode<Key, Value>* c = n -> getRight();
        if (c -> getBalance() == +1) {
          rotateLeft(n);
          n -> setBalance(0);
          c -> setBalance(0);
          removeFix(p, ndiff);
        } else if (c -> getBalance() == 0) {
          rotateLeft(n);
          n -> setBalance(+1);
          c -> setBalance(-1);
        } else if (c -> getBalance() == -1) {
          AVLNode<Key, Value>* g = c -> getLeft();
          rotateRight(c);
          rotateLeft(n);
          if (g -> getBalance() == -1) {
            n -> setBalance(0);
            c -> setBalance(+1);
            g -> setBalance(0);
          } else if (g -> getBalance() == 0) {
            n -> setBalance(0);
            c -> setBalance(0);
            g -> setBalance(0);
          } else if (g -> getBalance() == +1) {
            n -> setBalance(-1);
            c -> setBalance(0);
            g -> setBalance(0);
          }
          removeFix(p, ndiff);
        }
      } else if (n -> getBalance() + diff == +1) {
        n -> setBalance(+1);
      } else if (n -> getBalance() + diff == 0) {
        n -> setBalance(0);
        removeFix(p, ndiff);
      }

    }
  }
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix (AVLNode<Key, Value>* p, AVLNode<Key, Value>* n) {
  if (p == nullptr || p -> getParent() == nullptr) return;
  AVLNode<Key, Value>* g = p -> getParent();
  if (!isRightChild(p)) { // if p is leftchild of g
    g -> setBalance(g -> getBalance() - 1);
    if (g -> getBalance() == 0) {
      return;
    } else if (g -> getBalance() == -1) {
      insertFix(g, p);
    } else if (g -> getBalance() == -2) {
      if (!isRightChild(n)) { // if n is leftchild of g, then zigzig
        rotateRight(g);
      } else {
        rotateLeft(p);
        rotateRight(g);
      }
    }
  } else {
    g -> setBalance(g -> getBalance() + 1);
    if (g -> getBalance() == 0) {
      return;
    } else if (g -> getBalance() == 1) {
      insertFix(g, p);
    } else if (g -> getBalance() == 2) {
      if (isRightChild(n)) { // if n is leftchild of g, then zigzig
        rotateLeft(g);
      } else {
        rotateRight(p);
        rotateLeft(g);
      }
    }
  }
}

template<class Key, class Value>
bool AVLTree<Key, Value>::isRightChild (AVLNode<Key, Value>* n) // n must have a parent
{
  if (n -> getKey() > n -> getParent() -> getKey()) {
    return true;
  } else return false;
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateRight (AVLNode<Key, Value>* z)  // z must have a left child
{
  AVLNode<Key, Value>* y = z -> getLeft();
  AVLNode<Key, Value>* c = y -> getRight();

  y -> setRight(z);
  y -> setParent(z -> getParent());
  z -> setParent(y);

  z -> setLeft(c);
  if (c != nullptr) {
    c -> setParent(z);
  }

  if (z == static_cast<AVLNode<Key, Value>*>(this -> root_)) {
    this -> root_ = y;
  }
}

template<class Key, class Value>
void AVLTree<Key, Value>::rotateLeft (AVLNode<Key, Value>* z) // n must have a parent and a right child
{
  AVLNode<Key, Value>* y = z -> getRight();
  AVLNode<Key, Value>* c = y -> getLeft();

  y -> setLeft(z);
  y -> setParent(z -> getParent());
  z -> setParent(y);

  z -> setRight(c);
  if (c != nullptr) {
    c -> setParent(z);
  }

  if (z == static_cast<AVLNode<Key, Value>*>(this -> root_)) {
    this -> root_ = y;
  }
}

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{

  if (this -> empty())  {
    this -> root_ = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
    return;
  }

  AVLNode<Key, Value>* curr = static_cast<AVLNode<Key, Value>*>(this -> root_);

  // edge case when curr is the root and has no children
  if (curr -> getKey() == new_item.first) {
    curr -> setValue(new_item.second);
    return;
  } 

  while (curr != nullptr) {
    if (curr -> getKey() == new_item.first) {
      curr -> setValue(new_item.second);
      return;
    } else if (curr -> getKey() > new_item.first) {
      if (curr -> getLeft() != nullptr) {
        curr = curr -> getLeft();
      } else {
        AVLNode<Key, Value>* newAVLNode = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
        curr -> setLeft(newAVLNode);
        if (curr -> getBalance() == 0) {
          curr -> setBalance(-1);
          insertFix(curr, newAVLNode);
        }
        return;
      }
    } else {
      if (curr -> getRight() != nullptr) {
        curr = curr -> getRight();
      } else {
        AVLNode<Key, Value>* newAVLNode = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
        curr -> setRight(newAVLNode);
        if (curr -> getBalance() == 0) {
          curr -> setBalance(-1);
          insertFix(curr, newAVLNode); 
        }
        return;
      }
    }
  }

  if (new_item.first <= curr -> getKey()) {
    AVLNode<Key, Value>* newAVLNode = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
    curr -> setLeft(newAVLNode);
  } else {
    AVLNode<Key, Value>* newAVLNode = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
    curr -> setRight(newAVLNode);
  }

    // TODO
}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
  if (!(this -> empty())) {
    AVLNode<Key, Value>* curr = static_cast<AVLNode<Key, Value>*>(this -> root_);
    while (curr != nullptr) {
      if (curr -> getKey() == key) {
        if (curr -> getLeft() != nullptr && curr -> getRight() != nullptr) {
          AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>*>(this -> predecessor(curr));
          nodeSwap(curr, pred);
          AVLNode<Key, Value>* child = curr -> getLeft();
          AVLNode<Key, Value>* parent = curr -> getParent();
          int diff;
          if (pred -> getKey() <= parent -> getKey()) { // curr is at the left child pos
            parent -> setLeft(child);
            diff = 1;
            parent -> setBalance(parent -> getBalance() + 1);
            if (child != nullptr) {
              child -> setParent(parent);
            }
          } else { // curr is right child
            parent -> setRight(child);
            parent -> setBalance(parent -> getBalance() - 1);
            diff = -1;
            if (child != nullptr) {
              child -> setParent(parent);
            }
          }
          
          delete curr;
          curr = nullptr;
          removeFix(parent, diff);
          return;
        } else if (curr -> getLeft() == nullptr && curr -> getRight() != nullptr) {
          AVLNode<Key, Value>* tmp = curr;
          AVLNode<Key, Value>* child = curr -> getRight();
          AVLNode<Key, Value>* parent = curr -> getParent();

          if (parent != nullptr) {
            if (curr -> getKey() < parent -> getKey()) {
              parent -> setLeft(child);
              if (child != nullptr) {
                child -> setParent(parent);
              }
            } else {
              parent -> setRight(child);
              if (child != nullptr) {
                child -> setParent(parent);
              }
            }
            delete tmp;
            tmp = nullptr;
            return;
          } else {
            AVLNode<Key, Value>* tmp = static_cast<AVLNode<Key, Value>*>(this -> root_ -> getRight());
            tmp -> setParent(nullptr);
            delete this -> root_;
            this -> root_ = tmp;
            return;
          }
        }
        else if (curr -> getLeft() != nullptr && curr -> getRight() == nullptr) {
          AVLNode<Key, Value>* tmp = curr;
          AVLNode<Key, Value>* child = curr -> getLeft();
          AVLNode<Key, Value>* parent = curr -> getParent();
          if (parent != nullptr) {
            if (curr -> getKey() < parent -> getKey()) {
              parent -> setLeft(child);
              if (child != nullptr) {
                child -> setParent(parent);
              }
            } else {
              parent -> setRight(child);
              if (child != nullptr) {
                child -> setParent(parent);
              }
            }
            delete tmp;
            tmp = nullptr;
            return;
          } else {
            AVLNode<Key, Value>* tmp = static_cast<AVLNode<Key, Value>*>(this -> root_ -> getLeft());
            tmp -> setParent(nullptr);
            delete this -> root_;
            this -> root_ = tmp;
            return;
          }
        } else {
          if (curr -> getParent() != nullptr) {
            if (curr -> getKey() < curr -> getParent() -> getKey()) {
              curr -> getParent() -> setLeft(nullptr);
            } else {
              curr -> getParent() -> setRight(nullptr);
            }
            delete curr;
            curr = nullptr;
            return;
          } else {
            delete this -> root_;
            this -> root_ = nullptr;
            return;
          }
        }
      } else if (curr -> getKey() > key) {
        if (curr -> getLeft() != nullptr) {
          curr = curr -> getLeft();
        } else return;
      } else {
        if (curr -> getRight() != nullptr) {
          curr = curr -> getRight();
        } else return;
      }
    }

  }
    // TODO
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}


#endif
