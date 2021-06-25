from numpy import array
from graphviz import Digraph

import const
from table import MooreTable, MealyTable, moore_srt, cmp_to_key



class MMAutomat:

    @property
    def is_valid(self):
        return self.__is_valid

    @property
    def automat_type(self):
        return self.__type

    # public methods ==========================================================

    def from_file(self, input_file_name):
        """
        Read automat from file.
        """
        in_file = None
        self.__is_valid = True
        try:
            input_file_path = const.DATA_PATH + input_file_name
            in_file = open(input_file_path, "r", encoding="utf-8")
            strings_list = in_file.readlines()
            self.__type = strings_list[0].rstrip()
            self.__start_state = strings_list[1].rstrip()
            header = strings_list[2].rstrip().split()
            table = [strings_list[i].rstrip().split() for i in range(3, len(strings_list))]
            if self.__type == "moore":
                self.__table = MooreTable(header, table)
            elif self.__type == "mealy":
                self.__table = MealyTable(header, table)
            else:
                raise Exception()
        except Exception:
            self.__reset_internal_data()
            print("Error. Read data was failed.")
        finally:
            if in_file and in_file.readable():
                in_file.close()
        return self.__is_valid


    def convert(self):
        """
        Convert moore->mealy, mealy->moore.
        """
        try:
            if self.__type == "moore":
                self.__moore_to_mealy()
            elif self.__type == "mealy":
                self.__mealy_to_moore()
            else:
                raise Exception()
        except Exception:
            self.__reset_internal_data()
            print("Error. Converting was failed.")


    def minimize(self):
        """
        Minimize automat if possible.
        """
        try:
            self.__graph = None
            if self.__type == "mealy":
                self.convert()
                self.__minimize_moore()
                self.convert()
            elif self.__type == "moore":
                self.__minimize_moore()
            else:
                raise Exception()
        except Exception:
            self.__reset_internal_data()
            print("Error. Minimization was failed.")


    def save_as_graph(self, output_file_name):
        """
        Save automat graph as .dot & .png files.
        """
        is_success = False
        try:
            if not self.__graph:
                self.__graph = self.__make_graph()
            self.__graph.render(directory=const.DATA_PATH, filename=output_file_name, format="png")
            is_success = True
        except Exception:
            print("Error. Could not save as graph.")
        return is_success


    def save_as_table(self, output_file_name):
        """
        Save automat table to file.
        """
        is_success = False
        out_file = None
        try:
            out_file = open(const.DATA_PATH + output_file_name, "w")
            out_file.write(self.__type + "\n")
            out_file.write(self.__start_state + "\n")
            out_file.write(self.__table.as_str())
            is_success = True
        except Exception:
            print("Error. Could not save as table.")
        finally:
            if out_file and out_file.writable():
                out_file.close()
        return is_success

    # private methods =========================================================

    def __init__(self):
        self.__reset_internal_data()


    def __reset_internal_data(self):
        self.__is_valid = False
        self.__type = None
        self.__start_state = None
        self.__table = None
        self.__graph = None


    # convert -----------------------------------------------------------------

    def __moore_to_mealy(self):
        if not self.__is_valid: return

        mealy_header = []
        for col in range(self.__table.cols_count):
            moore_header_node, _ = self.__table.header_cell(col)
            mealy_header.append(moore_header_node)

        mealy_table = []
        for row in range(self.__table.rows_count):
            mealy_row = []
            for col in range(self.__table.cols_count):
                moore_table_node = self.__table.table_cell(row, col)
                if moore_table_node != const.BLANK:
                    signal = self.__table.node_signal(moore_table_node)
                    mealy_row.append(f"{moore_table_node}/{signal}")
                else:
                    mealy_row.append(const.BLANK)
            mealy_table.append(mealy_row)

        self.__type = "mealy"
        self.__table = MealyTable(mealy_header, mealy_table)
        self.__graph = None


    def __mealy_to_moore(self):
        if not self.__is_valid: return

        mealy2moore_header_cell = {} # like {'q0': ['q0/y1', 'q1/y2', ...], 'q2': ['q2/y1', 'q3/y3', ...], ...}
        mealy2moore_table_cell = {} # like {'q0/y1': 'q0', 'q0/y2': 'q1', 'q1/y1': 'q2', ...}
        unique_cells = self.__table.unique_cells()
        for i in range(len(unique_cells)):
            mealy_table_cell = unique_cells[i]
            moore_table_cell = "q" + str(i)
            mealy_node, signal = mealy_table_cell.split("/")
            moore_header_cells = mealy2moore_header_cell.get(mealy_node, [])
            moore_header_cells.append(f"{moore_table_cell}/{signal}")

            mealy2moore_header_cell[mealy_node] = moore_header_cells
            mealy2moore_table_cell[mealy_table_cell] = moore_table_cell

        moore_header = []
        moore_table = []
        for row in range(self.__table.rows_count):
            moore_row = []
            for col in range(self.__table.cols_count):
                mealy_table_node, signal = self.__table.table_cell(row, col)
                moore_table_cell = mealy2moore_table_cell.get(f"{mealy_table_node}/{signal}", None)
                mealy_header_node = self.__table.header_cell(col)
                moore_header_cells = mealy2moore_header_cell.get(mealy_header_node)
                for moore_header_cell in moore_header_cells:
                    if row == 0:
                        moore_header.append(moore_header_cell)
                    if moore_table_cell is not None:
                        moore_row.append(moore_table_cell)
                    else:
                        moore_row.append(const.BLANK)
            moore_table.append(moore_row)

        moore_header_cells = mealy2moore_header_cell.get(self.__start_state)
        node, signal = moore_header_cells[0].split("/")
        self.__start_state = node
        self.__type = "moore"
        self.__table = MooreTable(moore_header, moore_table)
        self.__graph = None

    # graph -------------------------------------------------------------------

    def __make_graph(self):
        graph = None
        try:
            graph = Digraph(name=self.__type)
            if self.__type == "moore":
                for col in range(self.__table.cols_count):
                    node, signal = self.__table.header_cell(col)
                    if node == self.__start_state:
                        graph.node(node, f"S {node}/{signal}")
                    else:
                        graph.node(node, f"{node}/{signal}")
                for row in range(self.__table.rows_count):
                    for col in range(self.__table.cols_count):
                        to_node = self.__table.table_cell(row, col)
                        if to_node != const.BLANK:
                            from_node, signal = self.__table.header_cell(col)
                            graph.edge(from_node, to_node, f"x{row}")
            elif self.__type == "mealy":
                for col in range(self.__table.cols_count):
                    node = self.__table.header_cell(col)
                    if node == self.__start_state:
                        graph.node(node, f"S {node}")
                    else:
                        graph.node(node, node)
                for row in range(self.__table.rows_count):
                    for col in range(self.__table.cols_count):
                        to_node, signal = self.__table.table_cell(row, col)
                        if to_node != const.BLANK:
                            from_node = self.__table.header_cell(col)
                            graph.edge(from_node, to_node, f"x{row}/{signal}")
        except Exception:
            graph = None
            print("Error. Could not make graph.")
        return graph

    # minimize ----------------------------------------------------------------

    def __minimize_moore(self):

        def node_to_group(grouped_table, replace_dict):
            new_grouped_table = {}
            for group_key in grouped_table:
                new_group = {}
                group = grouped_table.get(group_key)
                for col_key in group:
                    column = group.get(col_key)
                    column = [replace_dict.get(cell_value, None) for cell_value in column]
                    new_group[col_key] = column
                new_grouped_table[group_key] = new_group
            return new_grouped_table

        def update_table_groups(grouped_table, node_group):
            groups_count = len(grouped_table)
            grouped_table = node_to_group(grouped_table, node_group)
            new_grouped_table = {}
            new_node_group = {}
            new_groups_count = 0
            for group_key in grouped_table:
                group = grouped_table.get(group_key)
                group_columns = list(group.keys())
                skip_indexes = set()
                for i in range(len(group_columns)):
                    if i not in skip_indexes:
                        curr_col = group.get(group_columns[i])
                        col = self.__table.column(self.__table.node_index(group_columns[i]))
                        new_group = {group_columns[i]: col}
                        for j in range(i+1, len(group_columns)):
                            if j not in skip_indexes:
                                next_col = group.get(group_columns[j])
                                if curr_col == next_col:
                                    skip_indexes.add(j)
                                    col = self.__table.column(self.__table.node_index(group_columns[j]))
                                    new_group[group_columns[j]] = col
                        new_grouped_table[new_groups_count] = new_group
                        new_groups_count += 1
            new_node_group = {node: group for group in new_grouped_table for node in new_grouped_table.get(group)}
            if groups_count != new_groups_count:
                return update_table_groups(new_grouped_table, new_node_group)
            else:
                return grouped_table

        unique_cells = self.__table.unique_cells()
        grouped_table = {}
        for col in range(self.__table.cols_count):
            node, signal = self.__table.header_cell(col)
            if (node in unique_cells) or (node == self.__start_state):
                group_columns = grouped_table.get(signal, {})
                group_columns[node] = [n for n in self.__table.column(col)]
                grouped_table[signal] = group_columns
        node_group = {node: signal for signal in grouped_table for node in grouped_table.get(signal)}

        grouped_table = update_table_groups(grouped_table, node_group)

        header, table = [], []
        for group_key in grouped_table:
            group = grouped_table.get(group_key)
            group_nodes = list(group.keys())
            signal = self.__table.node_signal(group_nodes[0])
            node = f"q{group_key}"
            if self.__start_state in group_nodes:
                self.__start_state = node
            column = [f"q{group_key}" if group_key is not None else const.BLANK for group_key in group.get(group_nodes[0])]
            header.append(f"{node}/{signal}")
            table.append(column)
        table = array(table).T.tolist()
        self.__table = MooreTable(header, table)

        queue = [self.__start_state]
        h = []
        checked = set()
        while len(queue):
            node = queue.pop(0)
            if node not in checked and node != const.BLANK:
                queue.extend(self.__table.column(self.__table.node_index(node)))
                checked.add(node)
                h.append(node)
        h.sort(key=cmp_to_key(moore_srt))
        header, table = [], []
        for node in h:
            signal = self.__table.node_signal(node)
            header.append(f"{node}/{signal}")
            table.append(self.__table.column(self.__table.node_index(node)))
        table = array(table).T.tolist()
        self.__table = MooreTable(header, table)


    def determinize(self):
        pass