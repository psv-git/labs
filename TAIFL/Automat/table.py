from re import findall
from functools import cmp_to_key

import const



def moore_srt(item_1, item_2):
    n_ind_1 = int(findall(r"\d+", item_1)[0])
    n_ind_2 = int(findall(r"\d+", item_2)[0])
    if n_ind_1 > n_ind_2: return 1
    elif n_ind_1 == n_ind_2: return 0
    else: return -1


def mealy_srt(item_1, item_2):
    node_1, signal_1 = item_1.split("/")
    node_2, signal_2 = item_2.split("/")
    n_ind_1 = int(findall(r"\d+", node_1)[0])
    n_ind_2 = int(findall(r"\d+", node_2)[0])
    if n_ind_1 > n_ind_2: return 1
    elif n_ind_1 == n_ind_2:
        s_ind_1 = int(findall(r"\d+", signal_1)[0])
        s_ind_2 = int(findall(r"\d+", signal_2)[0])
        if s_ind_1 > s_ind_2: return 1
        elif s_ind_1 > s_ind_2: return 0
        else: return -1
    else: return -1



class MooreTable:

    @property
    def rows_count(self):
        return len(self.__table)

    @property
    def cols_count(self):
        return len(self.__header_nodes)


    def __init__(self, header, table):
        try:
            self.__header_nodes = []
            self.__header_signals = []
            for col in range(len(header)):
                node, signal = header[col].split("/")
                self.__header_nodes.append(node)
                self.__header_signals.append(signal)
            self.__table = []
            for row in range(len(table)):
                table_row = []
                for col in range(len(header)):
                    table_row.append(table[row][col])
                self.__table.append(table_row)
        except Exception:
            print("Error. Bad moore table data")
            raise


    def as_str(self):
        string = ""
        for col in range(self.cols_count):
            node = self.__header_nodes[col]
            signal = self.__header_signals[col]
            string += f"{node}/{signal}"
            if col < (self.cols_count - 1): string += " "
        string += "\n"
        for row in range(self.rows_count):
            for col in range(self.cols_count):
                string += self.__table[row][col]
                if col < (self.cols_count - 1): string += " "
            string += "\n"
        return string


    def header_cell(self, col):
        if (col is not None) and (col in range(self.cols_count)):
            return self.__header_nodes[col], self.__header_signals[col]
        return const.BLANK, const.BLANK


    def table_cell(self, row, col):
        if row in range(self.rows_count):
            if col in range(self.cols_count):
                return self.__table[row][col]
        return None


    def node_index(self, node):
        index = None
        try:
            index = self.__header_nodes.index(node)
        except ValueError:
            pass
        return index


    def node_signal(self, node):
        signal = None
        index = self.node_index(node)
        if index is not None:
            signal = self.__header_signals[index]
        return signal


    def unique_cells(self):
        unique_cells = []
        for row in range(self.rows_count):
            for col in range(self.cols_count):
                node = self.__table[row][col]
                if node != const.BLANK:
                    unique_cells.append(node)
        unique_cells = list(set(unique_cells))
        return unique_cells


    def row(self, row):
        if row in range(self.rows_count):
            return self.__table[row]


    def column(self, col):
        column = []
        if col in range(self.cols_count):
            for row in self.__table:
                column.append(row[col])
        return column



class MealyTable:

    @property
    def rows_count(self):
        return len(self.__table_nodes)

    @property
    def cols_count(self):
        return len(self.__header)


    def __init__(self, header, table):
        try:
            self.__header = header
            self.__table_nodes = []
            self.__table_signals = []
            for row in range(len(table)):
                table_nodes_row = []
                table_signals_row = []
                for col in range(len(header)):
                    if table[row][col] == const.BLANK:
                        node, signal = const.BLANK, const.BLANK
                    else:
                        node, signal = table[row][col].split("/")
                    table_nodes_row.append(node)
                    table_signals_row.append(signal)
                self.__table_nodes.append(table_nodes_row)
                self.__table_signals.append(table_signals_row)
        except Exception:
            print("Error. Bad mealy table data")
            raise


    def as_str(self):
        string = ""
        for col in range(self.cols_count):
            string += self.__header[col]
            if col < (self.cols_count - 1): string += " "
        string += "\n"
        for row in range(self.rows_count):
            for col in range(self.cols_count):
                node = self.__table_nodes[row][col]
                signal = self.__table_signals[row][col]
                if node == const.BLANK: string += const.BLANK
                else: string += f"{node}/{signal}"
                if col < (self.cols_count - 1): string += " "
            string += "\n"
        return string


    def header_cell(self, col):
        if col in range(self.cols_count):
            return self.__header[col]
        return None


    def table_cell(self, row, col):
        if row in range(self.rows_count):
            if col in range(self.cols_count):
                return self.__table_nodes[row][col], self.__table_signals[row][col]
        return None, None


    def unique_cells(self):
        unique_cells = []
        for row in range(self.rows_count):
            for col in range(self.cols_count):
                node = self.__table_nodes[row][col]
                signal = self.__table_signals[row][col]
                if node != const.BLANK:
                    unique_cells.append(f"{node}/{signal}")
        unique_cells = list(set(unique_cells))
        unique_cells.sort(key=cmp_to_key(mealy_srt))
        return unique_cells


    def column(self, col):
        column = []
        if col in range(self.cols_count):
            for i in range(self.rows_count):
                node = self.__table_nodes[i][col]
                signal = self.__table_signals[i][col]
                column.append(f"{node}/{signal}")
        return column
