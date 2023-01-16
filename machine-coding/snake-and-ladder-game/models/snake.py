from utilities import generate_unique_id


class Snake:
    def __init__(self, start, end):
        self.id = generate_unique_id()
        self.start = start
        self.end = end

    def get_start_position(self):
        return self.start

    def get_end_position(self):
        return self.end

    def get_id(self):
        return self.id
