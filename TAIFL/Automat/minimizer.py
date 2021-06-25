import sys

import const
from automat import MMAutomat



def automat_minimizer(input_file_name):
    a = MMAutomat()
    a.from_file(input_file_name)
    a.minimize()
    a.save_as_graph(const.OUTPUT_GRAPH)
    a.save_as_table(const.OUTPUT_TABLE)
    if a.is_valid:
        return 0
    return 1


# =============================================================================

if __name__ == "__main__":
    # program must have one arg like: input.txt
    if len(sys.argv) == 2:
        automat_minimizer(sys.argv[1])
    else:
        print("Use 'python3 ./app.py <input_file_name>'")
