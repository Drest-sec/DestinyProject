import pygame
from projectile import Projectile
import animation

#1ere classe qui va représenter notre joueur
class Player(animation.AnimateSprite):

    def __init__(self,game):
        super().__init__('player')
        self.game = game
        self.health = 150
        self.max_health = 150
        self.attack = 20
        self.velocity = 15
        self.all_projectiles = pygame.sprite.Group()
        self.rect = self.image.get_rect()
        self.rect.x = 500
        self.rect.y = 450

    def dammage(self, amount):
        if self.health - amount > amount:
            self.health -= amount
        else:
            # si les PV du joueur = 0
            self.game.game_over()

    def update_animation(self):
        self.animate()

    def update_health_bar(self, surface):

        # définir la position de notre jauge de vie ainsi que sa largeur et son épaisseur
        bar_position = [self.rect.x + 5, self.rect.y + 20, self.health, 7]
        # définir la position de l'arrière plan de notre jauge de vie
        back_bar_position = [self.rect.x + 5, self.rect.y + 20, self.max_health, 7]

        # dessiner notre barre de vie
        pygame.draw.rect(surface, (60,63,60), back_bar_position)
        pygame.draw.rect(surface, (111,210,46), bar_position)

    def launch_projectile(self):
        #creer une nouvelle instace de la classe projectile
        if len(self.all_projectiles) < 5:
            self.all_projectiles.add(Projectile(self))
        # démarrer l'animation du lancer
        self.start_animation()

    def move_right(self):
        # si le joueur n'est pas en collision avec un monstre
        if not self.game.check_collision(self, self.game.all_monsters):
            self.rect.x += self.velocity

    def move_left(self):
        # si le joueur n'est pas en collision avec un monstre
        if not self.game.check_collision(self, self.game.all_monsters):
            self.rect.x -= self.velocity

    def move_up(self):
        # si le joueur n'est pas en collision avec un monstre
        if not self.game.check_collision(self, self.game.all_monsters):
            self.rect.y -= self.velocity

    def move_down(self):
        # si le joueur n'est pas en collision avec un monstre
        if not self.game.check_collision(self, self.game.all_monsters):
            self.rect.y += self.velocity

