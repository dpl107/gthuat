import pygame
import random

# Khởi tạo Pygame
pygame.init()

# Kích thước màn hình
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Adventure Game")

# Màu sắc
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (200, 50, 50)
GREEN = (50, 200, 50)

# Font chữ
font = pygame.font.Font(None, 36)

# Lớp Player
class Player:
    def __init__(self):
        self.hearts = 5
        self.points = 0
        self.x, self.y = SCREEN_WIDTH // 2, SCREEN_HEIGHT - 100
        self.speed = 5
        self.width, self.height = 50, 50
        self.dodge_mode = False

    def move(self, keys):
        if keys[pygame.K_LEFT]:
            self.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.x += self.speed

    def attack(self, monster):
        damage = monster.health * 0.75
        monster.health -= damage
        self.points += 30
        return damage

    def draw(self):
        pygame.draw.rect(screen, GREEN, (self.x, self.y, self.width, self.height))

# Lớp Monster
class Monster:
    def __init__(self, is_boss=False):
        self.health = 2000 if is_boss else 1000
        self.x, self.y = random.randint(100, SCREEN_WIDTH - 100), 100
        self.width, self.height = 60, 60
        self.is_boss = is_boss
        self.bullets = []

    def attack(self, player):
        damage = 2 if self.is_boss else 1
        player.hearts -= damage
        return damage

    def spawn_bullets(self):
        for _ in range(5 if not self.is_boss else 10):
            self.bullets.append(Bullet(random.randint(200, 600), random.randint(200, 400), self.is_boss))

    def draw(self):
        color = RED if self.is_boss else BLACK
        pygame.draw.rect(screen, color, (self.x, self.y, self.width, self.height))

# Lớp Bullet (Đạn)
class Bullet:
    def __init__(self, x, y, is_boss):
        self.x = x
        self.y = y
        self.radius = 5
        self.speed = 3 if not is_boss else 6

    def move(self):
        self.y += self.speed

    def draw(self):
        pygame.draw.circle(screen, WHITE, (self.x, self.y), self.radius)

# Hàm hiển thị text
def draw_text(text, x, y, color=WHITE):
    render = font.render(text, True, color)
    screen.blit(render, (x, y))

# Hàm né đòn
def dodge_bullets(player, monster):
    player.dodge_mode = True
    monster.spawn_bullets()
    dodge_time = 3000  # 3 giây
    start_time = pygame.time.get_ticks()
    
    while pygame.time.get_ticks() - start_time < dodge_time:
        screen.fill((30, 30, 30))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return
        
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            player.x -= player.speed
        if keys[pygame.K_RIGHT]:
            player.x += player.speed
        if keys[pygame.K_UP]:
            player.y -= player.speed
        if keys[pygame.K_DOWN]:
            player.y += player.speed
        
        player.draw()
        for bullet in monster.bullets:
            bullet.move()
            bullet.draw()
            if pygame.Rect(player.x, player.y, player.width, player.height).colliderect(pygame.Rect(bullet.x, bullet.y, bullet.radius*2, bullet.radius*2)):
                player.hearts -= 1
                print("Hit!")
        
        draw_text(f"Hearts: {player.hearts}", 20, 20)
        pygame.display.flip()
        pygame.time.delay(30)
    
    player.dodge_mode = False

# Hàm chính
def game_loop():
    player = Player()
    monster = Monster()
    running = True

    while running:
        screen.fill((30, 30, 30))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                damage = player.attack(monster)
                print(f"Player attacked! Monster took {damage} damage.")
                if monster.health <= 0:
                    print("Monster defeated!")
                    monster = Monster(is_boss=random.choice([False, True]))
                else:
                    dodge_bullets(player, monster)
        
        keys = pygame.key.get_pressed()
        player.move(keys)
        
        player.draw()
        monster.draw()
        draw_text(f"Hearts: {player.hearts}", 20, 20)
        draw_text(f"Points: {player.points}", 20, 50)
        draw_text(f"Monster HP: {monster.health}", 20, 80)
        
        pygame.display.flip()
        pygame.time.delay(30)

    pygame.quit()

# Chạy game
if __name__ == "__main__":
    game_loop()
