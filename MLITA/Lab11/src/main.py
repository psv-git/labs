import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

seg_1 = None
seg_2 = None
res = "No"


def read():
    global root_path, input_path, seg_1, seg_2
    in_file = open(root_path + input_path, 'r')
    seg_1, seg_2 = read_file(in_file)
    in_file.close()


# исправил баундинг
def process():
    global seg_1, seg_2, res
    
    # print(seg_1)
    # print(seg_2)

    if seg_1.op == seg_2.op or seg_1.op == seg_2.cl or seg_1.cl == seg_2.op or seg_1.cl == seg_2.cl:
        res = "Yes"
    else:
        if is_bound(seg_1, seg_2):
            ar_1 = signed_double_triangle_area(seg_1, seg_2.op)
            ar_2 = signed_double_triangle_area(seg_1, seg_2.cl)
            ar_3 = signed_double_triangle_area(seg_2, seg_1.op)
            ar_4 = signed_double_triangle_area(seg_2, seg_1.cl)

            if ar_1 == 0 or ar_2 == 0 or ar_3 == 0 or ar_4 == 0: 
                res = "Yes"
            elif (ar_1 > 0 and ar_2 < 0 or ar_1 > 0 and ar_2 < 0) and (ar_3 > 0 and ar_4 < 0 or ar_3 > 0 and ar_4 < 0):
                res = "Yes"

    print("result: ", res)


def output():
    global root_path, output_path, res
    out_file = open(root_path + output_path, 'w')
    out_file.write(res)
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
