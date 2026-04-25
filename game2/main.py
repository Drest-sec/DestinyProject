import pygame
import math
from game import Game
pygame.init()

# définir une clock
clock = pygame.time.Clock()
FPS = 60

# générer la fenetre de notre jeu
pygame.display.set_caption("Space Shooter")
screen = pygame.display.set_mode((1270,680))

# importer l'arrière plan du jeu
background = pygame.image.load('assets/espace.jpg')

# importer la bannière pour l'acceuil
banner = pygame.image.load('assets/banner.png')
banner = pygame.transform.scale(banner,(550,500))
banner_rect = banner.get_rect()
banner_rect.x = math.ceil(screen.get_width() / 3.4)

# importer le bouton pour lancer la partie
play_button = pygame.image.load('assets/button.png')
play_button = pygame.transform.scale(play_button,(400,400))
play_button_rect = play_button.get_rect()
play_button_rect.x = math.ceil(screen.get_width() / 3)
play_button_rect.y = math.ceil(screen.get_height() / 1.80)

# charger le jeu
game = Game()

running = True

# boucle tant que cette condition est vrai
while running:

    # appliquer l'arrère plan du jeu
    screen.blit(background,(0,-400))

    # vérifier si le jeu a commencé ou non
    if game.is_playing:
        # déclencher les instructions de la partie
        game.update(screen)
    # vérifier si le jeu n'a pas commencé
    else:
        # ajouter mon écran de bienvenue
        screen.blit(play_button, play_button_rect)
        screen.blit(banner, banner_rect)

    # mettre à jour l'écran
    pygame.display.flip()

    # si le joueur ferme cette fenetre
    for event in pygame.event.get():
        # l'évènement est fermeture de fenetre
        if event.type == pygame.QUIT:
            running = False
            pygame.quit()
            print("Fermeture du jeu")

        # détecter si un joueur lache une touche du clavier
        elif event.type == pygame.KEYDOWN:
            game.pressed[event.key] = True
            # détecter si la touche espace du clavier est enclenchée pour lancer les projectiles
            if event.key == pygame.K_SPACE:
                game.player.launch_projectile()

        elif event.type == pygame.KEYUP:
            game.pressed[event.key] = False

        elif event.type == pygame.MOUSEBUTTONDOWN:
            # vérification pour savoir si la souris est en collision avec le boutton jouer
            if play_button_rect.collidepoint(event.pos):
                # mettre le jeu en mode "lancé"
                game.start()

    # fixer le nombre de fps sur ma clock
    clock.tick(FPS)