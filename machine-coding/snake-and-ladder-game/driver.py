from models.snake import Snake
from models.ladder import Ladder
from models.player import Player
from snake_ladder_service import SnakeLadderService


class Driver:
    def __init__(self):
        snakes_count = int(input())
        snakes = []
        for i in range(snakes_count):
            start, end = int(input().split())
            snakes.append(Snake(start, end))

        ladders_count = int(input())
        ladders = []
        for i in range(ladders_count):
            start, end = int(input().split())
            ladders.append(Ladder(start, end))

        players_count = int(input())
        players = []
        for i in range(players_count):
            name = input()
            players.append(Player(name))

        SnakeLadderService()