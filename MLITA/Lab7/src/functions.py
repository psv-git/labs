def read_file(file):
    line = file.readline()
    N = int(line)
    segments = []
    for i in range(N):
        line = file.readline()
        line = [int(x) for x in line.split()]
        segments.append((i+1, line[0], line[1]))
    return N, segments


def sort_cmp(a, b):
    if a[1] > b[1]:
        return 1
    if a[1] < b[1]:
        return -1
    if a[2] < b[2]:
        return 1
    if a[2] > b[2]:
        return -1
    return 0
