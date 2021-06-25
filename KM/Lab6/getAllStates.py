try:
    from getSuccessors import getSuccessors
except:
    print("unable to import getSuccessors")
    exit()


def uniq(lst):
    st = set()
    for el in lst:
        el = tuple(el)
        st.add(el)
    list(st)
    lst.clear()
    for el in st:
        el = list(el)
        lst.append(el)


def getAllStates(state0, depth):
    allStateList = []
    tmp = [state0]
    tmp1 = []
    for d in range(depth):
        for l in range(len(tmp)):
            tmp1.extend(getSuccessors(tmp[l]))
            allStateList.extend(tmp1.copy())
        tmp = tmp1.copy()
        tmp1.clear()
    uniq(allStateList)
    return(allStateList)
