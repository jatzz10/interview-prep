class Board:
    def __init__(self, size, ladders, snakes):
        self.DEFAULT_BOARD_SIZE = 100
        self.ladders = ladders
        self.snakes = snakes

    def get_size(self):
        return self.size

    def get_snakes(self):
        return self.snakes

    def get_ladders(self):
        return self.ladders

    def load_board(self):
        pass
