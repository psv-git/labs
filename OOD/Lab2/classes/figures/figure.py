from PyQt5.QtCore import QPoint
from PyQt5.QtGui import QColor

from configs import app_config as cnf
from classes.figures.i_figure import IFigure
from classes.primitives.rectangle_shape import RectangleShape
from classes.primitives.circle_shape import CircleShape



class Figure(IFigure):
    """
    Args:
        shape: IShape
    """

    # private methods =========================================================

    def __init__(self, shape):
        self.__is_active = False
        self.__shape = shape
        self.__shape.set_color(QColor(255, 255, 255, 255))
        self.__bounding_rect = self.__shape.get_bounding_rect()


    def __draw_bounding_box(self, canvas):
        bounding_shape = RectangleShape(self.__bounding_rect.topLeft(), self.__bounding_rect.bottomRight())
        bounding_shape.set_border_color(QColor(255, 0, 0, 255))
        bounding_shape.set_color(QColor(0, 0, 0, 0))

        tl_bounding_marker = CircleShape(self.__bounding_rect.topLeft(), 3)
        tl_bounding_marker.set_border_color(QColor(255, 0, 0, 255))
        tl_bounding_marker.set_color(QColor(255, 0, 0, 255))

        tr_bounding_marker = CircleShape(self.__bounding_rect.topRight(), 3)
        tr_bounding_marker.set_border_color(QColor(255, 0, 0, 255))
        tr_bounding_marker.set_color(QColor(255, 0, 0, 255))

        bl_bounding_marker = CircleShape(self.__bounding_rect.bottomLeft(), 3)
        bl_bounding_marker.set_border_color(QColor(255, 0, 0, 255))
        bl_bounding_marker.set_color(QColor(255, 0, 0, 255))

        br_bounding_marker = CircleShape(self.__bounding_rect.bottomRight(), 3)
        br_bounding_marker.set_border_color(QColor(255, 0, 0, 255))
        br_bounding_marker.set_color(QColor(255, 0, 0, 255))

        bounding_shape.draw_to(canvas)
        tl_bounding_marker.draw_to(canvas)
        tr_bounding_marker.draw_to(canvas)
        bl_bounding_marker.draw_to(canvas)
        br_bounding_marker.draw_to(canvas)


    # public methods ==========================================================

    def draw_to(self, canvas):
        """
        Draw figure on canvas.

        Args:
            canvas: QWidget
        """
        self.__shape.draw_to(canvas)
        if self.__is_active:
            self.__draw_bounding_box(canvas)


    def on_click(self, point, keyboard_modifier):
        """
        On click method.

        Args:
            point: QPoint
        """
        if self.__shape.is_contain(point):
            self.__is_active = True
        else:
            if keyboard_modifier != cnf.SHIFT_MODIFIER:
                self.__is_active = False


    def on_drag(self, point):
        if self.__is_active:
            self.__shape.move_to(point)
            self.__bounding_rect = self.__shape.get_bounding_rect()


    def add_figure(self, figure):
        """
        This is single object class. Method do nothing.
        """
        return
