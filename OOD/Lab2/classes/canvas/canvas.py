from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget

from configs import app_config as cnf
from classes.primitives.composite_shape import CompositeShape



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
        self.__shapes = {}
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
        for sh in self.__shapes.values():
            sh.draw_to(self)


    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.__drag_start_position = event.windowPos()

            keyboard_modifier = None
            if QApplication.keyboardModifiers() == Qt.ShiftModifier:
                keyboard_modifier = cnf.SHIFT_MODIFIER

            for sh in self.__shapes.values():
                sh.on_click(event.windowPos(), keyboard_modifier)

        self.update()


    def mouseMoveEvent(self, event):
        if event.buttons() & Qt.LeftButton:
            threshold = event.windowPos() - self.__drag_start_position
            if threshold.manhattanLength() < QApplication.startDragDistance():
                return

            # print(f"windowPos: {event.windowPos()}")
            # print(f"screenPos: {event.screenPos()}")
            # print(f"localPos: {event.localPos()}")
            # print(f"globalPos: {event.globalPos()}")
            # print("========================================")

            cursor_pos = event.windowPos()
            for sh in self.__shapes.values():
                sh.on_drag(cursor_pos)

        self.update()


    def keyPressEvent(self, event):
        if QApplication.keyboardModifiers() == Qt.ControlModifier:
            # keyboard_modifier = cnf.CTL_MODIFIER

            if event.key() == Qt.Key_G:
                active_shapes = []
                for sh in self.__shapes.values():
                    if sh.is_active():
                        active_shapes.append(sh)
                if len(active_shapes) > 1:
                    shape = CompositeShape(self, *active_shapes)
                    self.add_shape(shape)
                    for sh in active_shapes:
                        self.remove_shape(sh)
            if event.key() == Qt.Key_U:
                active_shapes = []
                for sh in self.__shapes.values():
                    if sh.is_active():
                        active_shapes.append(sh)
                if len(active_shapes) == 1:
                    for sh in active_shapes:
                        nsh = sh.get_nested_shapes()
                        if nsh is not None:
                            for s in nsh:
                                sh.remove_shape(s)
                                self.add_shape(s)
                        if sh.is_empty():
                            self.remove_shape(sh)

        self.update()


    # public methods ==========================================================

    def add_shape(self, shape):
        # print(shape)
        self.__shapes[shape.get_id()] = shape


    def remove_shape(self, shape):
        self.__shapes.pop(shape.get_id())