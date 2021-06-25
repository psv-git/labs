#include "TreeNode.hpp"


TreeNode::TreeNode(TreeNode *parent, int depth, NodeType nodeType, 
                  string title) {
  this->parent = parent;
  this->depth = depth;
  this->nodeType = nodeType;
  this->title = title;

  this->ind1 = 0;
  this->ind2 = 0;
}


TreeNode::~TreeNode() {
  deleteSons();
}

// ============================================================================

// удалить всех сыновей
void TreeNode::deleteSons() {
  for (int i = 0; i < sonsList.size(); i++) {
    delete sonsList[i];
  }
}

// ============================================================================

// добавить сына
TreeNode* TreeNode::addSon(int depth, NodeType nodeType, string title) {
  TreeNode *newNode = new TreeNode(this, depth, nodeType, title);
  sonsList.push_back(newNode);
  
  return newNode;
}

// вернуть указатель на родителя
TreeNode* TreeNode::getParent() {
  return parent;
}

// ============================================================================

// вернуть количество элементов в поддереве
int TreeNode::getElementsCount() {
  int elementsCount = 0;
  if (nodeType == NodeType::AND) {
    elementsCount = 1;
    for (int i = 0; i < sonsList.size(); i++)
      elementsCount *= sonsList[i]->getElementsCount();
  } else if (nodeType == NodeType::OR) {
    elementsCount = 0;
    for (int i = 0; i < sonsList.size(); i++)
      elementsCount += sonsList[i]->getElementsCount();
  } else if (nodeType == NodeType::LEAF) {
    elementsCount = 1;
  }

  return elementsCount;
}


// вернуть строку вывода для текущего узла
string TreeNode::getOutString() {
  string str;
  for (int i = 0; i < depth; i++) str += '-';
  if (nodeType == NodeType::AND) str += '*';
  else if (nodeType == NodeType::OR) str += '+';
  else if (nodeType == NodeType::LEAF) str += '=';
  str += title;

  return str;
}

// ============================================================================

bool TreeNode::out(bool changeElement) {
  cout << getOutString() << endl;

  bool result = false;

  switch (nodeType) {
    case NodeType::AND :
      for (int i = 0; i < sonsList.size(); i++) {
        if (changeElement) {
          if (ind1 == 0) && (sonsList[ind1]->out(changeElement)) {
            result = true;
          }
          if (i != sonsList.size() - 1 - ind1) {
            sonsList[i]->out(!changeElement);
          } else {
            if (sonsList[i]->out(changeElement)) {
              ind1++;
            } else {
              ind1 = sonsList.size() - 1;
            }
          }
        } else {
          sonsList[i]->out(changeElement);
        }
      }
      break;
    case NodeType::OR :
      if (sonsList[ind1]->out(changeElement)) ind1++;
      if (ind1 == sonsList.size()) {
        ind1 = 0;
        result = true;
      } else result = false;
      break;
    default:
      break;
  }

  return result;
}
