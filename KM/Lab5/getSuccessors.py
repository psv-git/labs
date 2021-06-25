# ЗАДАНИЕ: Необходимо написать функцию getSuccessors(state0), которая (может )использовать глобальные переменные dirshift, Xcoords, Ycoords   и для заданной (преподавателем) перестановки чисел от 0 до 8 в виде списка state0 :
# - определяет соседнюю перестановку state (в виде списка номеров фишек), которые можно достичь с помощью одного хода (перемещение 0-ка)
# - для каждой найденной соседней перестановки state формирует узел - список вида node = [act, state_i] - действие, которое привело к этой перестановке и саму перестановку 
# - формирует из всех построенных дочерних узлов список и возвращает его в качестве результата работы функции

# Например, для state0=[3, 0, 2, 4, 5, 8, 6, 1, 7] ваша функция getSuccessors(state0 должна вернуть в качестве результата вычисления:
# [['left', [0, 3, 2, 4, 5, 8, 6, 1, 7]],
# ['right', [3, 2, 0, 4, 5, 8, 6, 1, 7]],
# ['down', [3, 5, 2, 4, 0, 8, 6, 1, 7]]]


def getSuccessors(state):
    nodeList = []
    tmp = []

    # узнаем индекс элемента '0'
    for i in range(len(state)):
        if (state[i] == 0):
            ind = i
            break

    # узнаем размерность state
    dim = int(pow(len(state), 0.5))

    # узнаем координату
    Ycoord = ind // dim
    Xcoord = ind % dim

    if (Ycoord > 0):
        stateUp = state.copy()
        stateUp[ind], stateUp[ind-dim] = stateUp[ind-dim], stateUp[ind]
        tmp.append('up')
        tmp.append(stateUp)
        nodeList.append(tmp.copy())
        tmp.clear()
    
    if (Ycoord < dim-1):
        stateDown = state.copy()
        stateDown[ind], stateDown[ind+dim] = stateDown[ind+dim], stateDown[ind]
        tmp.append('down')
        tmp.append(stateDown)
        nodeList.append(tmp.copy())
        tmp.clear()

    if (Xcoord > 0):
        stateLeft = state.copy()
        stateLeft[ind], stateLeft[ind-1] = stateLeft[ind-1], stateLeft[ind]
        tmp.append('left')
        tmp.append(stateLeft)
        nodeList.append(tmp.copy())
        tmp.clear()

    if (Xcoord < dim-1):
        stateRight = state.copy()
        stateRight[ind], stateRight[ind+1] = stateRight[ind+1], stateRight[ind]
        tmp.append('right')
        tmp.append(stateRight)
        nodeList.append(tmp.copy())
        tmp.clear()

    return(nodeList)
