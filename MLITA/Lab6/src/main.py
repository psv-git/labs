import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

X = None
Y = None
res = 0
bp = 9


def read():
    global root_path, input_path, X, Y
    in_file = open(root_path + input_path, 'r')
    X, Y = read_file(in_file) # load data from file
    in_file.close()


def process():
    global X, Y, res, bp
    lng_x = string_to_long(X, bp)
    lng_y = string_to_long(Y, bp)
    sign, res = subtract(lng_x, lng_y, bp)
    res = long_to_string(res, sign, bp)



def output():
    global root_path, output_path, res
    out_file = open(root_path + output_path, 'w')
    out_file.write("{0}".format(res))
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
