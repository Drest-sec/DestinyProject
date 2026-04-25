import pygame
from bonus import Bonus, Attack,Defense,Sante
import random

class BonusEvent:

    # créer le compteur
    def __init__(self,game):
        self.percent = 0
        self.percent_speed = 40
        self.game = game

    def add_percent(self):
        self.percent += self.percent_speed / 100

    def reset_percent(self):
        self.percent = 0

    def is_full_loaded(self):
        return self.percent >= 100

    def full(self):
        # la barre est chargée
        bonus_spe = [Attack, Defense, Sante]
        if self.is_full_loaded():
            self.reset_percent()
            self.game.spawn_bonus(bonus_spe[random.randint(0,2)])

    def update_bar(self,surface):

        # ajouter du pourcentage
        self.add_percent()

        # déclencher le spawn du bonus
        self.full()

        # barre de pourcentage ( non afficher )
        pygame.draw.rect(surface, (187,11,11),
        [0, surface.get_height(), (surface.get_width()/100) * self.percent,10])
