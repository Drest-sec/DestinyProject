import random
import animation
import time
import threading

class Bonus(animation.AnimateSprite):

    def __init__(self,game,name,size):
        super().__init__(name,size)
        self.type = name
        self.game = game
        self.rect = self.image.get_rect()
        self.rect.x = random.randint(0, 950)
        self.rect.y = random.randint(10, 500)
        self.loot_amout = 10
        self.start_animation()

    def remove(self):
        self.game.all_bonus.remove(self)

    def apply_temporary_bonus(self, player, attribute, value, duration):
        def bonus_effect():
            setattr(player, attribute, getattr(player, attribute) + value)
            time.sleep(duration)
            setattr(player, attribute, getattr(player, attribute) - value)

        # Démarrer un nouveau thread pour appliquer le bonus temporaire
        bonus_thread = threading.Thread(target=bonus_effect)
        bonus_thread.start()

    def activate(self):
        # vérifier si le bonus entre en collision avec le joueur
        for player in self.game.check_collision(self, self.game.all_players):
            # supprimer le bonus
            self.remove()
            # ajouter le nombre de points
            self.game.add_score(self.loot_amout)
            # vérifier quel est le type de bonus
            if self.type == "attack":
                self.apply_temporary_bonus(player, "attack", 20, 10)
            elif self.type == "defense":
                self.apply_temporary_bonus(self.game.vaisseau, "attack", -2, 10)
                self.apply_temporary_bonus(self.game.alien, "attack", -3, 10)
            elif self.type == "sante":
                player.health += 20

class Attack(Bonus):
    def __init__(self,game):
        super().__init__(game, "attack",(100,50))

class Defense(Bonus):
    def __init__(self,game):
        super().__init__(game, "defense",(100,50))

class Sante(Bonus):
    def __init__(self,game):
        super().__init__(game, "sante",(100,50))