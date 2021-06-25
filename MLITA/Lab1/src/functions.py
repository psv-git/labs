# PRIVATE FUNCTIONS ===========================================================

def __is_row_empty(row):
    return not '1' in row

# PUBLIC FUNCTIONS ============================================================

def read_file(file):
    matrix = []
    shape = [0, 0]
    for index, line in enumerate(file):
        if index == 0:
            shape = [int(s) for s in line.split() if s.isdigit()]
        else:
            matrix.append(list(line[:-1]))
    return shape, matrix


def transpose(matrix):
    return [list(i) for i in zip(*matrix)] # generate transposed new matrix


def get_shape(matrix):
    return [len(matrix), len(matrix[0])]


def cut_matrix(matrix):
    shape = get_shape(matrix)
    # get first non empty row index
    first_index = 0
    for i in range(0, shape[0], 1):
        if not __is_row_empty(matrix[i]):
            first_index = i
            break
    # get last non empty row index
    last_index = 0
    for i in range(shape[0] - 1, 0, -1):
        if not __is_row_empty(matrix[i]):
            last_index = i + 1
            break
    matrix = matrix[first_index:last_index] # cut matrix
    matrix.insert(0, ['0' for i in range(len(matrix[0]))]) # add first zero row
    matrix.insert(last_index+1, ['0' for i in range(len(matrix[0]))]) # add last zero row
    return matrix


def print_matrix(matrix):
    for row in matrix:
        print(row)

# =============================================================================

def map_from_image(image_file_path, map_file_path):
    from PIL import Image
    import numpy as np

    map_file = open(map_file_path, 'w')
    image = Image.open(image_file_path).convert("1")
    image = np.asarray(image, dtype=np.uint8)
    map_file.write(str(image.shape[0]))
    map_file.write(" ")
    map_file.write(str(image.shape[1]))
    map_file.write('\n')
    for row in image:
        for pixel in row:
            if pixel == 1: pixel = '0'
            else: pixel = '1'
            map_file.write(pixel)
        map_file.write('\n')
    map_file.close()
