import sys, os
import timeit
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

N = None
D = None
seq = None
res = 0


def read():
    global root_path, input_path, N, D, seq
    in_file = open(root_path + input_path, 'r')
    N, D, seq = read_file(in_file)
    in_file.close()


def number_from(file):
    num = ""
    s = file.read(1)
    if s == "": # EOF
        return None
    while s != " " and s != "\n":   # read by symbol
        num += s
        s = file.read(1)
    return int(num)



# добавил оптимизации, работу с файлом
# Занятие 5 10.3 связный поиск в линейных списках
def process():
    global N, D, seq, res

    # with open(root_path + input_path, 'r') as in_file:
    #     line = in_file.readline().split()
    #     N, D = int(line[0]), int(line[1])

    #     curr_ind = 0
    #     next_ind = 1
    #     curr_num = number_from(in_file) + D # read first number
    #     curr_pos = in_file.tell() # save next number pos
    #     next_pos = curr_pos
    #     is_last_iter = False

    #     while curr_ind < N:
    #         seq_flag = False
    #         curr_count = 0
    #         in_file.seek(next_pos)

    #         for i in range(next_ind, N):
    #             tmp_pos = in_file.tell()
    #             num = number_from(in_file) # read number

    #             if curr_num < num:
    #                 if not seq_flag:
    #                     next_ind = i
    #                     next_pos = tmp_pos
    #                 break
    #             elif curr_num == num:
    #                 if not seq_flag:
    #                     next_ind = i
    #                     next_pos = tmp_pos # hold on pos on first seq number
    #                     seq_flag = True
    #                 curr_count += 1
    #             else:
    #                 if i == N-1:
    #                     is_last_iter = True # curr_num > num and i == N-1; no more possible

    #         curr_ind += 1
    #         if curr_ind < N:
    #             # optimisation for sequenses
    #             prev_num = curr_num
    #             while curr_num is not None:
    #                 res += curr_count
    #                 in_file.seek(curr_pos)
    #                 curr_num = number_from(in_file)
    #                 if curr_num is not None:
    #                     curr_num += D
    #                     curr_pos = in_file.tell()
    #                     if curr_num != prev_num:
    #                         break

    #         # just optimisation
    #         if is_last_iter:
    #             break

    curr_ind = 0
    next_ind = 1
    curr_num = seq[curr_ind] + D
    prev_num = curr_num
    is_last_iter = False

    while curr_ind < N:
        seq_flag = False
        curr_count = 0

        for i in range(next_ind, N):
            if curr_num < seq[i]:
                if not seq_flag:
                    next_ind = i
                break
            elif curr_num == seq[i]:
                if not seq_flag:
                    next_ind = i
                    seq_flag = True
                curr_count += 1
            else:
                if i == N-1:
                    is_last_iter = True # curr_num > num and i == N-1; no more possible

        if curr_ind < N:
            # optimisation for sequenses
            prev_num = curr_num
            while curr_ind < N:
                res += curr_count
                curr_ind += 1
                if curr_ind == N:
                    break
                curr_num = seq[curr_ind] + D
                if curr_num != prev_num:
                    break

        # just optimisation
        if is_last_iter:
            break


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
