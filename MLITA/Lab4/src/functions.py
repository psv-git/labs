def read_file(file):
    N = int(file.readline())
    struct = []
    for _ in range(N):
        line = [[int(j), 0] for j in file.readline().split()]
        struct.append(line)
    return N, struct
