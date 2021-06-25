import sys, os
import timeit
from functools import cmp_to_key
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

N = None
seg = None
s_cnt = 0
s_num = []


def read():
    global root_path, input_path, N, seg
    in_file = open(root_path + input_path, 'r')
    N, seg = read_file(in_file)
    in_file.close()


# 3, 4, 6, 7, 8, 10
# не сделано
def process():
    global N, seg, s_cnt, s_num

    seg.sort(key=cmp_to_key(sort_cmp))

    # print(seg)

    i = 0
    seg_count = len(seg)
    s_num.append(seg[seg_count-1][0]) # last segment will be simple always

    while i < seg_count:
        is_simple_found = True
        is_duplicate_found = False
        j = i+1

        while j < seg_count:

            # check on outer segment
            if seg[i][2] < seg[j][1]:  # outer segment, dont touch it
                break

            # check on duplicates
            if seg[i][1] == seg[j][1]:  # skip duplicate
                if seg[i][2] == seg[j][2]:
                    is_duplicate_found = True
                    i += 1
            else:
                if is_duplicate_found:  # just skip all duplicated, no more
                    break

            #
            if not is_duplicate_found:
                if seg[i][2] >= seg[j][2]:  # found included segment, all segments from i to j not simple
                    is_simple_found = False
                    i = j-1
                    break

            j += 1

        if is_simple_found and not is_duplicate_found and i != seg_count-1:
            s_num.append(seg[i][0])

        i += 1

    s_num.sort()
    s_cnt = len(s_num)

    # print(s_cnt)
    # print(s_num)


def output():
    global root_path, output_path, s_cnt, s_num
    out_file = open(root_path + output_path, 'w')
    out_file.write("{0}".format(s_cnt))
    out_file.write("\n")
    out_file.write(" ".join(map(str, s_num)))
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
