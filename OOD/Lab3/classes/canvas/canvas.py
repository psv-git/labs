from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QPainter, QColor, QPen, QPainterPath, QBrush



class Canvas(QWidget):

    # private methods =========================================================

    def __init__(self, title=None, geometry=None):
        """
        Args:
            title: string
            geometry: QRect or list like [0, 0, 0, 0]
        """
        super().__init__()
        self.__title = title
        self.__geometry = geometry
        self.__figures_list = []
        self.__init_ui()


    def __init_ui(self):
        self.__check_title()
        self.__check_geometry()
        if isinstance(self.__geometry, list):
            self.setGeometry(self.__geometry[0], self.__geometry[1], self.__geometry[2], self.__geometry[3])
        else:
            self.setGeometry(self.__geometry)
        self.setWindowTitle(self.__title)


    def __check_title(self):
        if not isinstance(self.__title, str):
            self.__title = "Default title"


    def __check_geometry(self):
        if isinstance(self.__geometry, list):
            if len(self.__geometry) < 4: 
                self.__geometry = None
            else: 
                self.__geometry = [int(i) for i in self.__geometry]
        if self.__geometry is None:
            self.__geometry = QApplication.desktop().screenGeometry()


    # public methods ==========================================================

    def add_figure(self, figure):
        self.__figures_list.append(figure)


    def paintEvent(self, event):
        self.draw_figures()

    
    def draw_figures(self):
        for figure in self.__figures_list:
            figure.draw(self)
