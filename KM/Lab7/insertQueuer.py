# nodeNumsList - список номеров узлов, 
# Queuer  - очередь номеров узлов на раскрытие в порядке неубывания стоимости пути до узла вида
# Queuer = [(1,1), (2,1), (3,1), (4,2)]. Реализуется в виде списка кортежей вида (nodeId, cost)
# ФУНКЦИЯ берет список узлов с номерами nodeNumsList из списка allnodeslist и затем номера этих узлов ставит в очередь Queuer в соответствии с требованием неубывания cost - стоимости пути до  узла. При этом, если два узла имеют одинаковую стоимость cost, то первым в очереди оказывается тот узел, который раньше поставлен в очередь. функция ничего не возвращает, просто изменяет очередь Queuer

def insertQueuer(nodeNumsList, Queuer, allnodeslist):
  if(len(nodeNumsList) > 0):
    for index in range(len(nodeNumsList)):
      nodeNum = nodeNumsList[index]
      q = (nodeNum, allnodeslist[nodeNum]['cost'])
      Queuer.append(q)
  return(True)
