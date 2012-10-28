class AvlTree {
  
  public:
    AvlTree() : root(0) {  }

    void insert(double d) {
      if (!root) root = new AvlNode(d);
      else insert(root, d);
    }

    void printHeight() {
      std::cout<<std::endl;
      std::cout<<height(root);
      std::cout<<std::endl;
    }

    void print() const { print(root); }
  
  private:
    struct AvlNode {
      AvlNode(double d) : data(d), left(0), right(0) { }
      double data;
      AvlNode *left, *right;
    }; 

    void rotate_right(AvlNode* &node) {
      AvlNode *temp = node->left;
      node->left = temp->right;
      temp->right = node;
      node = temp;
    }

    void rotate_right_left(AvlNode* &node){
      rotate_right(node->right);
      rotate_left(node);
    }

    void rotate_left(AvlNode* &node){
      AvlNode *temp = node->right;
      node->right = temp->right;
      temp->left = node;
      node = temp;
    }

    void rotate_left_right(AvlNode* &node){
      rotate_left(node->left);
      rotate_right(node);
    }

    void insert(AvlNode* &node, double d) {
      if (!node) node = new AvlNode(d);
      if (d < node->data) {
        insert(node->left, d);
        if (height(node->left) - height(node->right) == 2) {
          if (d < node->left->data) rotate_right(node);
          else rotate_left_right(node);
        }
      }
      else if (d > node->data) {
        insert(node->right, d);
        if (height(node->right) - height(node->left) == 2) {
          if (d > node->right->data) rotate_left(node);
          else rotate_right_left(node);
        }
      }
    }

    unsigned height(AvlNode *node) const {
      if (!node) return 0;
      return 1 + std::max(height(node->left), height(node->right));
    }

    void print(AvlNode *node) const {
      if (!node) return;
      print(node->left);
      printf("%.2f (%d)\n", node->data, height(node));
      print(node->right);
    }

    AvlNode *root;
};