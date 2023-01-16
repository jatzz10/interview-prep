from utilities import generate_unique_id


class Player:
    def __init__(self, name):
        self.name = name
        self.id = generate_unique_id()
        self.position = 0

    def get_name(self):
        return self.name

    def get_id(self):
        return self.id

    def get_position(self):
        return self.position

    def set_position(self, new_position):
        self.position = new_position
