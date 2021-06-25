def getSuccessors(state):
    nodeList = []
    ind = state.index(0)
    dim = int(pow(len(state), 0.5))
    Ycoord = ind // dim
    Xcoord = ind % dim
    if (Ycoord > 0):
        stateUp = state.copy()
        stateUp[ind], stateUp[ind-dim] = stateUp[ind-dim], stateUp[ind]
        nodeList.append(stateUp)
    if (Ycoord < dim-1):
        stateDown = state.copy()
        stateDown[ind], stateDown[ind+dim] = stateDown[ind+dim], stateDown[ind]
        nodeList.append(stateDown)
    if (Xcoord > 0):
        stateLeft = state.copy()
        stateLeft[ind], stateLeft[ind-1] = stateLeft[ind-1], stateLeft[ind]
        nodeList.append(stateLeft)
    if (Xcoord < dim-1):
        stateRight = state.copy()
        stateRight[ind], stateRight[ind+1] = stateRight[ind+1], stateRight[ind]
        nodeList.append(stateRight)
    return(nodeList)
