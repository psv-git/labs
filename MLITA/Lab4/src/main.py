import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

N = None
struct = None
max_value = 0
nums = []


def read():
    global root_path, input_path, N, struct
    in_file = open(root_path + input_path, 'r')
    N, struct = read_file(in_file) # load data from file
    in_file.close()


def process():
    global N, struct, max_value, nums

    # print(struct)
    
    # forward pass
    left_border = 0
    for i in range(1, N):
        right_border = len(struct[i])-1
        for j in range(right_border+1):
            if j > left_border:  left_sum =  struct[i][j][0] + struct[i-1][j-1][0]
            if j < right_border: right_sum = struct[i][j][0] + struct[i-1][j][0]
            
            if j > left_border and j < right_border:
                if left_sum > right_sum: 
                    struct[i][j][0] = left_sum
                    struct[i][j][1] = j-1
                else: 
                    struct[i][j][0] = right_sum
                    struct[i][j][1] = j
            else:
                if j > left_border: 
                    struct[i][j][0] = left_sum
                    struct[i][j][1] = j-1
                else: 
                    struct[i][j][0] = right_sum
                    struct[i][j][1] = j
    
    # seek maximum value and previous node index in last line
    curr_val = struct[N-1][0][0]
    prev_ind = struct[N-1][0][1]
    for i in range(1, len(struct[N-1])):
        if struct[N-1][i][0] > curr_val: 
            curr_val = struct[N-1][i][0]
            prev_ind = struct[N-1][i][1]
    max_value = curr_val

    # backward pass
    for i in range(N-2, -1, -1):
        nums.append(curr_val - struct[i][prev_ind][0])
        curr_val = struct[i][prev_ind][0]
        prev_ind = struct[i][prev_ind][1]
    nums.append(struct[0][0][0])

    # print(struct)
    # print(max_value)
    # print(nums[::-1])


def output():
    global root_path, output_path, max_value, nums
    out_file = open(root_path + output_path, 'w')
    out_file.write(str(max_value) + "\n")
    out_file.write(" ".join(map(str, nums[::-1])))
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
