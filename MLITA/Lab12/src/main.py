import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

NC = None # nodes count
AC = None # arcs count
SN = None # start node
arcs = []
res = []
is_loop = False


def read():
    global root_path, input_path, NC, AC, SN, arcs
    in_file = open(root_path + input_path, 'r')
    NC, AC, SN, arcs = read_file(in_file)
    in_file.close()


# 1, 11
def process():
    global NC, AC, SN, arcs, res, is_loop

    D = [] # save max paths from SN node to each node
    P = [-1] * NC # save previous node for each node

    for i in range(NC):
        if i == SN-1: D.append(0) # node-1 because start list index is 0 not 1
        else: D.append(None)

    i = 0
    last_node = 0
    while True:
        is_break = True
        for j in range(AC):
            first_node = arcs[j][0]-1
            if D[first_node] is not None:
                second_node = arcs[j][1]-1
                cost = arcs[j][2]
                if D[second_node] is not None:
                    if D[second_node] < D[first_node] + cost:
                        D[second_node] = D[first_node] + cost
                        P[second_node] = first_node
                        is_break = False
                        if i == NC-1: 
                            last_node = second_node
                else:
                    D[second_node] = D[first_node] + cost
                    P[second_node] = first_node
                    is_break = False
                    if i == NC-1:
                        last_node = second_node
        if is_break: 
            break
        i += 1
    if i == NC: 
        is_loop = True

    if is_loop:
        # get node on loop
        for i in range(NC): 
            last_node = P[last_node]
        # get loop path
        path = [last_node+1]
        i = P[last_node]
        while True:
            path.append(i+1)
            i = P[i]
            if i == last_node:
                path.append(i+1)
                break
        res.append("No")
        res.append(path)
    else:
        for i in range(NC):
            path = []
            par_ind = i
            nodes_count = 0
            path_length = 0
            if P[i] < 0 and i != SN-1:
                path.append("No")
            else:
                while par_ind >= 0:
                    path.append(par_ind+1)
                    par_ind = P[par_ind]
                    nodes_count += 1
                    path_length = D[i]
                path.append(nodes_count)
                path.append(path_length)
            res.append(path[::-1])

    # print(res)


def output():
    global root_path, output_path, res, is_loop
    out_file = open(root_path + output_path, 'w')
    if is_loop:
        out_file.write(res[0] + "\n")
        out_file.write(str(len(res[1])) + " ")
        for i in range(len(res[1])):
            out_file.write(str(res[1][i]))
            if i != len(res[1])-1:
                out_file.write(" ")
    else:
        for l in res:
            out_file.write(" ".join(map(str, l)) + "\n")
    out_file.close()

# =============================================================================

read_time = timeit.timeit(read, number=1)
process_time = timeit.timeit(process, number=1)
output_time = timeit.timeit(output, number=1)

print("Reading time: {0}".format(read_time))
print("Processing time: {0}".format(process_time))
print("Output time: {0}".format(output_time))
print("Total time: {0}".format(read_time + process_time + output_time))

# =============================================================================
