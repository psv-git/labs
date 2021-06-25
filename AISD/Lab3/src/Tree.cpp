#include "Tree.hpp"


Tree::Tree() {
  root = nullptr;
  currDepth = 0;
}


Tree::~Tree() {
  if (root) 
    delete root;
}

// ============================================================================

// парсинг входного файла и создание дерева
void Tree::readTree(istream &inFile) {
  if (!inFile.eof()) {
    NodeType nodeType = NodeType::BLANK;
    string str, title;
    int depth = 0;
    getline(inFile, str);
    if (!str.empty()) {
      for (int i = 0; i < str.size(); i++) {
        if (nodeType == NodeType::BLANK) {
          if (str[i] == '*') nodeType = NodeType::AND;
          else if (str[i] == '+') nodeType = NodeType::OR;
          else if (str[i] == '=') nodeType = NodeType::LEAF;
          else depth++;
        } else title += str[i];
      }
      if (root) {
        if (depth < currDepth) {
          for (int i = 0; i <= currDepth - depth; i++) {
            currNode = currNode->getParent();
          }
        } else if (depth == currDepth) {
          currNode = currNode->getParent();
        }
        currDepth = depth;
        currNode = currNode->addSon(currDepth, nodeType, title);
      } else {
        root = new TreeNode(nullptr, currDepth, nodeType, title);
        currNode = root;
      }
    }
    readTree(inFile);
  }
}


// вывод элементов дерева
void Tree::writeElements() {
  cout << "Количество элементов в дереве: " << 
                    root->getElementsCount() << endl << endl;

  for (int i = 0; i < root->getElementsCount(); i++) {
    root->out(true);
    cout << endl;
  }
}
