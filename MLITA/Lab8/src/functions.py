def read_file(file):
    line = file.readline()
    line = [int(s) for s in line.split()]
    N, D = line[0], line[1]
    line = file.readline().split()
    line = [int(s) for s in line]
    return N, D, line
