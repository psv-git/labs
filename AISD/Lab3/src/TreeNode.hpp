#ifndef TREENODE_H
#define TREENODE_H


#include "Headers.hpp"


class TreeNode {

  public:

    TreeNode(TreeNode *parent, int depth, NodeType nodeType, string title);
    ~TreeNode();

    TreeNode* addSon(int depth, NodeType nodeType, string title);
    TreeNode* getParent();
    int getElementsCount();

    bool out(bool changeElement);

  private:

    TreeNode *parent; // указатель на родителя
    vector<TreeNode*> sonsList; // список указателей на сыновей

    int depth; // глубина вложенности узла
    NodeType nodeType; // Тип узла - OR, AND, LEAF
    string title; // имя узла

    // рабочие индексаторы для И/ИЛИ вершин
    int ind1, ind2;

    string getOutString();
    void deleteSons();

};


#endif
