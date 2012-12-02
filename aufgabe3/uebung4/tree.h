#ifndef TREE_H_
#define TREE_H_

#include <iostream>

template <typename T>

class Tree {
  public:
    Tree() : root(0) {  }
    ~Tree(){
      clearNodes();
    }

    void insert(T d) {
      if (!root) root = new Node(d);
      else insert(root, d);
    }

    unsigned height() const {
        return height(root);
    }

    void print() const { print(root); }
    void clearNodes(){ clearNodes(root); }

  private:
    struct Node {
      Node(T d) : data(d), left(0), right(0) {  }
      T data;
      Node *left, *right;
    };

    void print(Node *node) const {
      if (!node) return;
      print(node->left);
      std::cout << node->data << std::endl;
      print(node->right);
    }

    unsigned height(Node *node) const {
      if (!node) return 0;
      return 1 + std::max(height(node->left), height(node->right));
    }

    void insert(Node* &node, double d) {
      if (!node) node = new Node(d);
      if (d < node->data)insert(node->left, d);
      else if (d > node->data) insert(node->right, d);
    }

    void clearNodes(Node *node){
      if(!node) return;
      clearNodes(node->left);
      clearNodes(node->right);
      delete node;
    }

    Node *root;
};

#endif