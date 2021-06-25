# GLOBAL VARIABLES

dirshift = {'left': (-1,0),'right': (1,0), 'up': (0,-1), 'down': (0,1)}
Xcoords = (0,1,2,0,1,2,0,1,2)
Ycoords = (0,0,0,1,1,1,2,2,2)
nodesCount = 0

# state: состояние игры в "8", например state = [1,2,3,4,5,6,7,8,0]
# функция возращает 'nextstate' - соседнее состояние, если 'act' - действие, 
# которое переводит игру из состояния state в nextstate
# функция возвращает [], если ход недопустимый

def getSuccessor(state, act):
  zeroindex = state.index(0)
  Xzero = Xcoords[zeroindex]
  Yzero = Ycoords[zeroindex]
  nextRow = Yzero + dirshift[act][1]
  nextCol = Xzero + dirshift[act][0]
  if(not(nextRow in range(3) and nextCol in range(3))):
    return([])
  nextstate = state[:]
  nextNum = nextCol + 3*nextRow
  nextstate[zeroindex] = state[nextNum]
  nextstate[nextNum] = 0
  return(nextstate)


# Вход: nodeId - номер узла в списке allnodeslist. 
# node = {'act': 'Stop', 'cost': 0, 'node_id': 0, 'parentnode_id': -1, 'state': [1,2,3,4,5,6,7,8,0]}
# Выход: генерация дочерных узлов и включение их в список allnodeslist nodeNumsList = [node1, node2, ...]  - список номеров дочерних узлов в allnodeslist
   
def expand(nodeId, allnodeslist):
  global nodesCount
  node = allnodeslist[nodeId]
  nodeNumsList = []
  state = node['state']
  actions = ['left', 'right', 'up', 'down']
  for index in range(4):
    action = actions[index]
    newState = getSuccessor(state, action)
    if (len(newState) > 0):
      nodesCount += 1
      newNode = { 'act': action, 'cost': node['cost'] + 1, 'node_id': nodesCount, 'parentnode_id': nodeId, 'state': newState }
      allnodeslist.append(newNode)
      nodeNumsList.append(nodesCount)
  return(nodeNumsList)
