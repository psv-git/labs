import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

line = None
res = []


def read():
    global root_path, input_path, line
    in_file = open(root_path + input_path, 'r')
    line = read_file(in_file)
    in_file.close()


# добавил перенос строки в input файлы
def process():
    global line, res

    line.sort()
    line_len = len(line)

    while 1:
        is_found = False
        res.append("".join(line) + "\n")
        for i in range(line_len-1, 0, -1):
            if line[i] > line[i-1]:
                is_found = True
                i_min = i
                for j in range(i_min, line_len):
                    if line[j] > line[i-1] and line[j] <= line[i_min]:
                        i_min = j
                line[i-1], line[i_min] = line[i_min], line[i-1]
                line = line[:i:] + line[i::][::-1]
            if is_found: break
        if not is_found: break
    # print(len(res))


def output():
    global root_path, output_path, res
    out_file = open(root_path + output_path, 'w')
    for line in res:
        out_file.write(line)
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
