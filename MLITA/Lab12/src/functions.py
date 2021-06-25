def read_file(file):
    line = file.readline().split()
    NC = int(line[0])
    AC = int(line[1])
    SN = int(line[2])
    arcs = []
    for _ in range(AC):
        line = file.readline().split()
        arcs.append([int(line[0]), int(line[1]), int(line[2])])
    return NC, AC, SN, arcs
