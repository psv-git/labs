import sys, os
import timeit
from functions import *
from classes import Board


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
if len(sys.argv) > 2:
    output_path = sys.argv[2]

shape = None
matrix = None

# =============================================================================

def read():
    global root_path, input_path, shape, matrix
    inp_file = open(root_path + input_path, 'r')
    shape, matrix = read_file(inp_file) # load data from file
    inp_file.close()


def process():
    global root_path, output_path, shape, matrix

    matrix = cut_matrix(matrix) # cut matrix by empty rows
    matrix = cut_matrix(transpose(matrix)) # cut matrix by empty columns

    board = Board(matrix)

    out_file = open(root_path + output_path, "w")
    out_file.write(str(board.run()))
    out_file.close()
    # print_matrix(matrix)

# =============================================================================

print("Reading complete: time - {0}".format(timeit.timeit(read, number=1)))
print("Processing complete: time - {0}".format(timeit.timeit(process, number=1)))

# =============================================================================
