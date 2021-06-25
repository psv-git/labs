class IFigure:
    """
    It just declare childs interface, no more.
    """

    # virtual methods =========================================================

    def draw_to(self, canvas):
        raise NotImplementedError()


    def on_click(self, point, keyboard_modifier):
        raise NotImplementedError()


    def add_figure(self, figure):
        raise NotImplementedError()
