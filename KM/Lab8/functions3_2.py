from operator import itemgetter

# Функция для узла с id = nodeId из списка allNodesList 
# формирует список дочерних узлов дерева поиска и добавляет их
# в список allNodesList и помещает их id в nodesIdList

# Вход: nodeId - id узла в списке allNodesList
# node = {'act': 'Stop', 'cost': 0, 'node_id': 0, 'parentnode_id': -1, 'state': [1,2,3,4,5,6,7,8,0]}
# Выход: генерация дочерных узлов и включение их в список allNodesList nodesIdList = [node1, node2, ...]  - список id дочерних узлов в allNodesList

def expand(nodeId, allNodesList):
  node = allNodesList[nodeId]
  nodesIdList = []
  state = node['state']
  actions = setActions(node)
  for i in range(len(actions)):
    action = actions[i]
    newNodeState = getSuccessor(state, action)
    if (len(newNodeState) > 0):
      newNodeId = len(allNodesList)
      newNodeCost = node['cost'] + 1
      newNode = { 'act': action, 'cost': newNodeCost, 'node_id': newNodeId, 'parentnode_id': nodeId, 'state': newNodeState }
      allNodesList.append(newNode)
      nodesIdList.append(newNodeId)
  return(nodesIdList)


def setActions(node):
  actions = ['left', 'right', 'up', 'down']
  if (node['act'] == 'left'):
    actions.remove('right')
  elif (node['act'] == 'right'):
    actions.remove('left')
  elif (node['act'] == 'up'):
    actions.remove('down')
  elif (node['act'] == 'down'):
    actions.remove('up')
  return(actions)


# state: состояние игры в "8", например state = [1,2,3,4,5,6,7,8,0]
# Функция возращает 'newstate' - соседнее состояние, если 'act' - действие, 
# которое переводит игру из состояния state в newstate
# Функция возвращает [], если ход недопустимый

def getSuccessor(state, act):
  ind = state.index(0)
  dim = int(pow(len(state), 0.5))
  Xcoord = ind % dim
  Ycoord = ind // dim
  nextState = []
  if (act == 'left') and (Xcoord > 0):
    nextState = state.copy()
    nextState[ind], nextState[ind-1] = nextState[ind-1], nextState[ind]
  elif (act == 'right') and (Xcoord < dim-1):
    nextState = state.copy()
    nextState[ind], nextState[ind+1] = nextState[ind+1], nextState[ind]
  elif (act == 'up') and (Ycoord > 0):
    nextState = state.copy()
    nextState[ind], nextState[ind-dim] = nextState[ind-dim], nextState[ind]
  elif (act == 'down') and (Ycoord < dim-1):
    nextState = state.copy()
    nextState[ind], nextState[ind+dim] = nextState[ind+dim], nextState[ind]
  return(nextState)


# nodesIdList - список id узлов, 
# Queuer  - очередь id узлов на раскрытие в порядке неубывания стоимости пути до узла вида
# Queuer = [(1,1), (2,1), (3,1), (4,2)]. Реализуется в виде списка кортежей вида (nodeId, priority)

# Функция берет список узлов с номерами nodesIdList из списка allNodesList и затем номера этих узлов ставит в очередь Queuer в соответствии с требованием неубывания priority - оценка стоимости пути до цели. При этом, если два узла имеют одинаковую стоимость priority, то первым в очереди оказывается тот узел, который раньше поставлен в очередь. Функция ничего не возвращает, просто изменяет очередь Queuer

def insertQueuer(nodesIdList, Queuer, allNodesList):
  if(len(nodesIdList) > 0):
    for i in range(len(nodesIdList)):
      nodeId = nodesIdList[i]
      priority = priorityfun(allNodesList[nodeId])
      Queuer.append((nodeId, priority))
  return(True)


# для заданного узла node= (act, cost, node_id, parent_id, state)  вычисляет
# приоритет узла для постановки его впоследствии в очередь Queuer.

def priorityfun(node):
  priority = node['cost'] + heuristicfun(node['state'])
  return(priority)


# для заданного состояния игры state  оценивает минимальный остаток пути 
# до цели для оценки приоритета узла (оценки длины пути через узел).

def heuristicfun(state):
  h=0
  dim = int(pow(len(state), 0.5))
  for i in range(len(state)):
    val = state[i]
    if (val != 0):
      Xdest = val % dim
      Ydest = val // dim
      Xcurr = i % dim
      Ycurr = i // dim
      h += abs(Xdest - Xcurr) + abs(Ydest - Ycurr)
  return(h)


def getInverseCount(state):
  inverseCount = 0
  for i in range(len(state)-1):
    if (state[i] > state[i+1]):
      state[i], state[i+1] = state[i+1], state[i]
      inverseCount += 1
      inverseCount += getInverseCount(state)
  return(inverseCount)
