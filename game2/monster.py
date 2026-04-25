import pygame
import random
import animation


# créer une classe qui va gérer la notion de monstre sur le jeu
class Monster(animation.AnimateSprite):

    def __init__(self,game,name, size, offset=0):
        super().__init__(name, size)
        self.game = game
        self.rect = self.image.get_rect()
        self.rect.x = 1000 + random.randint(0,300)
        self.rect.y = random.randint(10,500) + offset
        self.loot_amout = 10
        self.start_animation()

    def set_speed(self, speed):
        self.default_speed = speed
        self.velocity = random.randint(1, speed)

    def set_loot_amount(self, amount):
        self.loot_amout = amount

    def damage(self, amount):
        # infliger des dégats
        self.health -= amount

        # vérifier si son nombre de PV <= 0
        if self.health <= 0:
            # réapparaitre comme un nouveau monstre
            self.rect.x = 1000 + random.randint(0,300)
            self.velocity = random.randint(1,self.default_speed)
            self.health = self.max_health
            # ajouter le nombre de points
            self.game.add_score(self.loot_amout)

            if self.game.score >= 0 and self.game.score <= 500:
                self.game.all_monsters.remove(self)
            elif self.game.score >= 501 and self.game.score <= 1000:
                self.game.all_monsters.remove(self)
            elif self.game.score >= 1001 and self.game.score <= 1500:
                self.game.all_monsters.remove(self)
            elif self.game.score >= 1501 and self.game.score <= 2000:
                self.game.all_monsters.remove(self)

    def update_animation(self):
        self.animate(loop=True)

    def update_health_bar(self, surface):

        # définir la position de notre jauge de vie ainsi que sa largeur et son épaisseur
        bar_position = [self.rect.x + 10, self.rect.y - 20, self.health, 5]
        # définir la position de l'arrière plan de notre jauge de vie
        back_bar_position = [self.rect.x + 10, self.rect.y - 20, self.max_health, 5]

        # dessiner notre barre de vie
        pygame.draw.rect(surface, (60,63,60), back_bar_position)
        pygame.draw.rect(surface, (111,210,46), bar_position)

    def forward(self):
        # déplacement ne se fait que si il n'y a pas de collision avec le groupe de joueur
        if not self.game.check_collision(self, self.game.all_players):
            self.rect.x -= self.velocity
        # si le monstre est en collisition avec le joueur
        else:
            # infliger des dégats au joueur
            self.game.player.dammage(self.attack)

# définir une classe pour la momie
class Vaisseau(Monster):

    def __init__(self,game):
        super().__init__(game, "vaisseau", (130,130),75)
        self.health = 100
        self.max_health = 100
        self.attack = 1
        self.set_speed(3)
        self.set_loot_amount(20)

# définir une classe pour l'alien
class Alien(Monster):

    def __init__(self,game):
        super().__init__(game, "alien", (150,150), 20)
        self.health = 200
        self.max_health = 200
        self.attack = 2
        self.set_speed(1)
        self.set_loot_amount(40)
