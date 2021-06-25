import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

N = None
res = 0


def read():
    global root_path, input_path, N
    in_file = open(root_path + input_path, 'r')
    N = read_file(in_file)
    in_file.close()


def process():
    global N, res

    seq_2 = [2, 4, 2, 2, 4, 2, 2, 4, 2, 2]
    N = [int(i) for i in N[::-1]]
    n_len = len(N)

    if n_len == 1:
        res += get_count(seq_2_to_seq_1(seq_2), N[0], 0) # 0-9 range
    else:
        for i in range(2, n_len): # 100-N range
            new_seq_2 = []
            for j in range(10):
                seq_2_sum = sum(seq_2)
                if j < N[i]:
                    res += seq_2_sum
                if i != n_len-1:
                    new_seq_2.append(seq_2_sum)
                    seq_2_left_shift(seq_2)
                elif j < N[i]:
                    seq_2_left_shift(seq_2)
            if i != n_len-1:
                seq_2 = new_seq_2
            print(res)

        print("".join(map(str, N[::-1])))
        # print(seq_2)
        print(res)
        res += get_count(seq_2_to_seq_1(seq_2), N[0], N[1]) # 0-N[1] range
        print(res)

# TEST ========================================================================

    # i = 1
    # last_two = []
    # while i < 10701:
    #     if i % 5 != 0:
    #         if i % 3 != 0:
    #             res += 1
    #             if len(last_two) == 4:
    #                 last_two.pop(0)
    #             last_two.append(i)
    #     i += 2
    # print(last_two)
    # print("i: {0}, res: {1}".format(i, res))

    # k = 0
    # rt = []
    # for t in range(0, 10000, 1000):
    #     rh = []
    #     for h in range(0, 1000, 100):
    #         rd = []
    #         for d in range(0, 100, 10):
    #             ri = 0
    #             for i in range(1, 10, 2):
    #                 if (t + h + d + i) % 5 != 0:
    #                     if (t + h + d + i) % 3 != 0:
    #                         ri += 1
    #             rd.append(ri)
    #         print(rd)
    #         rh.append(sum(rd))
    #     k += 1
    #     print("thousand: {0}  ".format(k), rh)
    #     rt.append(sum(rh))
    # print(rt)



def output():
    global root_path, output_path, res
    out_file = open(root_path + output_path, 'w')
    out_file.write(str(res))
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
