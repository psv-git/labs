from functions3_2 import expand, insertQueuer, getInverseCount
from operator import itemgetter


# программа построение дерева универсального поиска
# формирует список всех узлов allNodesList
# формирует очередь узлов Queuer в порядке неубывания priority - стоимости пути
# организует поиск оптимального пути


def aStarSearch(startState, expandNodesQ = 1000):
  startNode = {'act': 'Stop', 'cost': 0, 'node_id': 0, 'parentnode_id': -1, 'state': startState} # начальный узел
  allNodesList = [startNode] # список сгенерированных узлов
  Queuer = [] # очередь узлов на раскрытие
  path = []  # путь решения

  currState = startState.copy()
  currState.remove(0)
  if (getInverseCount(currState) % 2 == 0):
    qNode = (0, 0)
    currState = startState
    expandCounter = 0
    while (getInverseCount(currState.copy()) > 0) and (expandCounter < expandNodesQ):
      nodesIdList = expand(qNode[0], allNodesList)
      insertQueuer(nodesIdList, Queuer, allNodesList)
      Queuer.sort(key=itemgetter(1))
      qNode = Queuer.pop(0)
      print(qNode)
      currState = allNodesList[qNode[0]]['state']
      expandCounter += 1
    currNode = allNodesList[qNode[0]]
    while (currNode['node_id'] != startNode['node_id']):
      path.append(currNode['act'])
      currNode = allNodesList[currNode['parentnode_id']]
    path.reverse()
    return(path)
  else:
    return(False)
