import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

X = None
Y = None
res = None


def read():
    global root_path, input_path, X, Y
    in_file = open(root_path + input_path, 'r')
    X, Y = read_file(in_file) # load data from file
    in_file.close()


def process():
    global X, Y, res

    if X == Y: 
        res = 1
    else:
        res = 0
        if is_even(X) == is_even(Y) and X < Y:
            m = {(X, Y): 1}
            for y in range(Y - 1, -1, -1): # from y-1 to y==0
                for x in range(y, 0, -2): # skip x>y, x==0 ; step 2
                    lt_val = m.get((x + 1, y + 1), 0) # get left top cell value
                    rt_val = m.get((x - 1, y + 1), 0) # get right top cell value
                    m[(x, y)] = lt_val + rt_val       # set current cell value
                if y == 0:
                    res = m.get((1, 1), None) # check (x=1, y=1) cell on result value


def output():
    global root_path, output_path, X, Y, res
    out_file = open(root_path + output_path, 'w')
    out_file.write("{0}".format(res))
    out_file.close()

    print(X, Y)
    print(res)

# =============================================================================

read_time = timeit.timeit(read, number=1)
process_time = timeit.timeit(process, number=1)
output_time = timeit.timeit(output, number=1)

print("Reading time: {0}".format(read_time))
print("Processing time: {0}".format(process_time))
print("Output time: {0}".format(output_time))
print("Total time: {0}".format(read_time + process_time + output_time))

# =============================================================================
