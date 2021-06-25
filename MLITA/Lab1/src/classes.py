import functions as func
from collections import deque


class Board:

    def __init__(self, matrix):
        shape = func.get_shape(matrix)
        self.__shape = (shape[0] - 1, shape[1] - 1)
        self.__board = matrix
        self.__board[0][0] = 'X' # zero patient
        self.__next_cells = deque([(0, 0)])
        self.__walls_count = 0

# PRIVATE METHODS =============================================================

    def __check_cell(self, y, x, aa):
        cell_value = self.__board[y][x]
        if cell_value == '0':
            self.__board[y][x] = 'X' # infected him; add to queue
            return True
        if cell_value == '1':
            self.__walls_count += 1 # its a wall; count it
            # self.d[aa] += 1 # TEST
        return False

    # def __form_dict(self):
    #     for y in range(self.__shape[0]+1):
    #         for x in range(self.__shape[1]+1):
    #             self.d[(y, x)] = 0

# PUBLIC METHODS ==============================================================

    def run(self):
        # self.__form_dict() # TEST

        while len(self.__next_cells) > 0:
            curr_cell = self.__next_cells.popleft()
            curr_y = curr_cell[0]
            curr_x = curr_cell[1]

            if curr_y > 0:
                if self.__check_cell(curr_y - 1, curr_x, (curr_y, curr_x)):
                    self.__next_cells.append((curr_y - 1, curr_x))
            if curr_y < self.__shape[0]:
                if self.__check_cell(curr_y + 1, curr_x, (curr_y, curr_x)):
                    self.__next_cells.append((curr_y + 1, curr_x))
            if curr_x > 0:
                if self.__check_cell(curr_y, curr_x - 1, (curr_y, curr_x)):
                    self.__next_cells.append((curr_y, curr_x - 1))
            if curr_x < self.__shape[1]:
                if self.__check_cell(curr_y, curr_x + 1, (curr_y, curr_x)):
                    self.__next_cells.append((curr_y, curr_x + 1))

        # print(self.d) # TEST
        return self.__walls_count