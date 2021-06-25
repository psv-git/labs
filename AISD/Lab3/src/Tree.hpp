#ifndef TREE_H
#define TREE_H


#include "Headers.hpp"
#include "TreeNode.hpp"


class Tree {
    
  public:

    Tree();
    ~Tree();

    void readTree(istream &inFile);
    void writeElements();

  private:

    TreeNode *root; // указатель на корень

    // переменные для создания дерева
    TreeNode *currNode;
    int currDepth;

};


#endif
