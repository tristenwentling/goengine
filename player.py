

class Player(object):
    """creates a player for game with attributes"""

    def __init__(self):
        self._pid = None

    def set_pid(self, string):
        self._pid = string
