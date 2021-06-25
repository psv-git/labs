import sys, os
import timeit
from collections import deque
from functions import *


root_path = os.getcwd() # get path to directory
input_path = sys.argv[1] # get first arg (must be relative path to input file)
output_path = "/data/output"

is_blocked = False

shape = None
wheels_list = None
wheels_dict = None
wheels_state_dict = None


def read():
    global input_path, root_path, shape, wheels_list, wheels_dict
    in_file = open(root_path + input_path, 'r')
    shape, wheels_dict = read_file(in_file) # load data from file
    wheels_list = list(wheels_dict.keys())
    wheels_list.sort()
    in_file.close()


def process():
    global is_blocked, wheels_list, wheels_dict, wheels_state_dict
    immovable = 0
    clockwise = 1
    unclockwise = 2

    queue = deque([wheels_list[0]])
    wheels_state_dict = {wheels_list[0]: clockwise}

    while len(queue) > 0 and not is_blocked:
        active_wheel = queue.popleft()
        active_wheel_state = wheels_state_dict.get(active_wheel, immovable)
        passive_wheels_list = wheels_dict.get(active_wheel)
        for passive_wheel in passive_wheels_list:
            passive_wheel_state = wheels_state_dict.get(passive_wheel, immovable)

            # check on block
            is_blocked = active_wheel_state == passive_wheel_state
            if is_blocked: break

            if passive_wheel_state == immovable: # set passive wheel state
                if active_wheel_state == clockwise:
                    wheels_state_dict[passive_wheel] = unclockwise
                else:
                    wheels_state_dict[passive_wheel] = clockwise
                queue.append(passive_wheel)



def output():
    global root_path, output_path, shape, wheels_dict, wheels_state_dict
    out_file = open(root_path + output_path, 'w')

    if is_blocked:
        out_file.write("blocked\n")
    else:
        l = shape[0] + 1
        for wheel in range(1, l):
            state = wheels_state_dict.get(wheel, 0)
            if state == 0:
                out_file.write("immovable\n")
            elif state == 1:
                out_file.write("clockwise\n")
            else:
                out_file.write("unclockwise\n")
    out_file.close()

# =============================================================================

print("Reading complete: time - {0}".format(timeit.timeit(read, number=1)))
print("Processing complete: time - {0}".format(timeit.timeit(process, number=1)))
print("Output complete: time - {0}".format(timeit.timeit(output, number=1)))

# =============================================================================

# generate_test(root_path + input_path, 100000, 100000)