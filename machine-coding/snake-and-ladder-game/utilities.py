import uuid
import random


def generate_unique_id():
    return uuid.uuid1()


def generate_random_number():
    return random.choice([1, 2, 3, 4, 5, 6])
