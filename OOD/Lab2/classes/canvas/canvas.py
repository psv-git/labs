from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget

from configs import app_config as cnf



class Canvas(QWidget):
    """
    Args:
        title: string
        geometry: QRect or list like [0, 0, 0, 0]
    """

    # private methods =========================================================

    def __init__(self, title=None, geometry=None):
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
            self.__title = cnf.DEFAULT_TITLE


    def __check_geometry(self):
        if isinstance(self.__geometry, list):
            if len(self.__geometry) < 4: 
                self.__geometry = None
            else: 
                self.__geometry = [int(i) for i in self.__geometry]
        if self.__geometry is None:
            self.__geometry = QApplication.desktop().screenGeometry()

    
    # Qt callback methods =====================================================

    def paintEvent(self, event):
        for figure in self.__figures_list:
            figure.draw_to(self)


    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.__drag_start_position = event.windowPos()

            keyboard_modifier = None
            if QApplication.keyboardModifiers() == Qt.ShiftModifier:
                keyboard_modifier = cnf.SHIFT_MODIFIER

            for figure in self.__figures_list:
                figure.on_click(event.windowPos(), keyboard_modifier)
            self.update()


    def mouseMoveEvent(self, event):
        if event.buttons() & Qt.LeftButton:
            threshold = event.windowPos() - self.__drag_start_position
            if threshold.manhattanLength() < QApplication.startDragDistance():
                return

            point = event.windowPos()
            for figure in self.__figures_list:
                figure.on_drag(point)
            
            self.update()


    def keyPressEvent(self, event):
        keyboard_modifier = None
        if QApplication.keyboardModifiers() == Qt.ControlModifier:
            keyboard_modifier = cnf.CTL_MODIFIER
            
            if event.key() == Qt.Key_G:
                print("G handler")
            if event.key() == Qt.Key_U:
                print("U handler")


    # public methods ==========================================================

    def add_figure(self, figure):
        self.__figures_list.append(figure)
