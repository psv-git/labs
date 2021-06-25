import logging
from PyQt5.QtCore import QObject, QPoint

from configs import app_config as cnf
from classes.canvas.canvas import Canvas
from classes.primitives.circle_shape import CircleShape
from classes.primitives.triangle_shape import TriangleShape
from classes.primitives.rectangle_shape import RectangleShape
from classes.figures.figure import Figure
# from classes.decorators.print_to_console_decorator import PrintToConsoleDecorator
# from classes.decorators.save_to_file_decorator import SaveToFileDecorator



class AppHandler(QObject):

    # private methods =========================================================

    def __init__(self, input_file_path, output_file_path):
        super().__init__()

        try:
            self.__make_canvas()
            self.__read_input_file(input_file_path)
            self.__process(output_file_path)
        except:
            print("Initialize AppHandler error. Application will be closed.")
            # self.deleteLater()
            raise


    def __read_input_file(self, input_file_path):
        strings_list = []
        self.__shapes_list = []
        try:
            with open(cnf.ROOT_PATH + input_file_path, "r", encoding="utf-8") as in_file:
                strings_list = in_file.readlines()
                for string in strings_list:
                    string = string.strip("\n")
                    string = string.split(" ")
                    string = [sub_str.strip(";") for sub_str in string]
                    shape = None
                    if string[0] == "CIRCLE:":
                        center_point = string[1][2::].split(",")
                        center_point = QPoint(int(center_point[0]), int(center_point[1]))
                        radius = int(string[2][2::])
                        shape = CircleShape(center_point, radius)
                    else: 
                        point_1 = string[1][3::].split(",")
                        point_1 = QPoint(int(point_1[0]), int(point_1[1]))
                        point_2 = string[2][3::].split(",")
                        point_2 = QPoint(int(point_2[0]), int(point_2[1]))
                        if string[0] == "TRIANGLE:":
                            point_3 = string[3][3::].split(",")
                            point_3 = QPoint(int(point_3[0]), int(point_3[1]))
                            shape = TriangleShape(point_1, point_2, point_3)
                        else:
                            shape = RectangleShape(point_1, point_2)
                    self.__shapes_list.append(shape)
        except:
            print("Input file not found.")
            raise


    def __make_canvas(self):
        self.__canvas = Canvas("Lab 1")


    def __show_canvas(self):
        self.__canvas.show()


    def __process(self, output_file_path):
        for shape in self.__shapes_list:
            # figure = PrintToConsoleDecorator(SaveToFileDecorator(figure, output_file_path))
            # figure_type, perimeter, area = figure.get_parameters()
            figure = Figure(shape)
            self.__canvas.add_figure(figure)
        self.__show_canvas()
