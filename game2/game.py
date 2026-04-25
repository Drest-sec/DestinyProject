from player import Player
from monster import Monster, Vaisseau, Alien
import pygame
from bonus_bar import BonusEvent

# créer une classe qui va représenter le jeu
class Game:

    def __init__(self):
        # définir si le jeu a commencé ou non
        self.is_playing = False
        # générer le joueur
        self.all_players = pygame.sprite.Group()
        self.player = Player(self)
        self.all_players.add(self.player)
        self.vaisseau = Vaisseau(self)
        self.alien = Alien(self)
        # groupe de monstre
        self.all_monsters = pygame.sprite.Group()
        # groupe de bonus
        self.all_bonus = pygame.sprite.Group()
        # générer la barre de chargement
        self.bonus_bar = BonusEvent(self)
        # mettre le score à 0
        self.font = pygame.font.SysFont("monospace",25)
        self.score = 0
        self.pressed = {}
        self.mode = False

    def start(self):
        self.is_playing = True

    # gérer la difficulté
    def difficult(self):
        # mode facile
        if self.score >= 0 and self.score <= 500:
            if len(self.all_monsters) == 0:
                for facile in range(0, 3):
                    self.spawn_monster(Vaisseau)
                    self.spawn_monster(Alien)
                self.vaisseau.set_speed(3)
                self.alien.set_speed(1)
        # mode moyen
        elif self.score >= 501 and self.score <= 1000:
            if len(self.all_monsters) == 0:
                for facile in range(0, 4):
                    self.spawn_monster(Vaisseau)
                    self.spawn_monster(Alien)
                self.vaisseau.set_speed(5)
                self.alien.set_speed(2)
        # mode dificile
        elif self.score >= 1001 and self.score <= 1500:
            if len(self.all_monsters) == 0:
                for facile in range(0, 5):
                    self.spawn_monster(Vaisseau)
                    self.spawn_monster(Alien)
                self.vaisseau.set_speed(7)
                self.alien.set_speed(3)
        # mode hardcore
        elif self.score >= 1501 and self.score <= 2000:
            if len(self.all_monsters) == 0:
                for facile in range(0, 8):
                    self.spawn_monster(Vaisseau)
                    self.spawn_monster(Alien)
                self.vaisseau.set_speed(10)
                self.alien.set_speed(4)

    def add_score(self, points = 10):
        self.score += points

    def game_over(self):
        # remettre le jeu à neuf
        self.all_monsters = pygame.sprite.Group()
        self.player.health = self.player.max_health
        self.is_playing = False
        self.score = 0
        self.bonus_bar.reset_percent()

    def update(self, screen):

        # mettre la difficulté
        self.difficult()
        #afficher le score sur l'écran
        score_text = self.font.render(f"Score : {self.score}", 1, (252, 252, 252))
        screen.blit(score_text, (20,20))

        # appliquer l'image du joueur
        screen.blit(self.player.image, self.player.rect)

        # actualiser la barre de vie du joueur
        self.player.update_health_bar(screen)

        # actualiser l'animation du joueur
        self.player.update_animation()

        # récupérer les projectiles du joueur
        for projectile in self.player.all_projectiles:
            projectile.move()

        # appliquer ensemble des images
        self.player.all_projectiles.draw(screen)

        # vérifier si le joueur va à gauche ou droite
        if self.pressed.get(pygame.K_RIGHT) and self.player.rect.x + self.player.rect.width < screen.get_width():
            self.player.move_right()
        elif self.pressed.get(pygame.K_LEFT) and self.player.rect.x > 0:
            self.player.move_left()
        if self.pressed.get(pygame.K_UP) and self.player.rect.y > -60:
            self.player.move_up()
        elif self.pressed.get(pygame.K_DOWN) and self.player.rect.y < 550:
            self.player.move_down()

        # récupérer les monstres du jeu
        for monster in self.all_monsters:
            monster.forward()
            monster.update_health_bar(screen)
            monster.update_animation()

        # appliquer l'ensemble des images de mon groupe de monstre
        self.all_monsters.draw(screen)

        # actualiser la barre de chargement des bonus
        self.bonus_bar.update_bar(screen)

        # récupérer les bonus du jeu
        for bonus in self.all_bonus:
             bonus.activate()

        # appliquer l'ensemble des images de mon groupe de bonus
        self.all_bonus.draw(screen)

    def check_collision(self, sprite, group):
        return pygame.sprite.spritecollide(sprite, group, False, pygame.sprite.collide_mask)

    def spawn_monster(self, monster_class_name):
        self.all_monsters.add(monster_class_name.__call__(self))

    def spawn_bonus(self, bonus_class_name):
        self.all_bonus.add(bonus_class_name.__call__(self))