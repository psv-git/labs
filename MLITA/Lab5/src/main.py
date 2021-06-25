import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

M = None
N = None
res = 0


def read():
    global root_path, input_path, M, N
    in_file = open(root_path + input_path, 'r')
    M, N = read_file(in_file) # load data from file
    in_file.close()


# не учитывалось последнее число если оно степень десятки
def process():
    global M, N, res

    if M == N:
        res = get_digit_count(M)
    else:
        next_number = M
        while next_number < N:
            next_number, count_val = f(next_number, N)
            res += count_val


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
