import random
import sys

class Player:
    def __init__(self):
        self.hearts = 50.0
        self.points = 0
        self.level = 1
        self.items = []
        self.rare_items = ["Huyết Nguyệt Kiếm", "Long Tộc Chi Giáp"]
        
    def add_rare_item(self):
        if len(self.items) < 2:
            item = random.choice([i for i in self.rare_items if i not in self.items])
            self.items.append(item)
            print(f"Bạn vừa nhận được vật phẩm hiếm: {item}!")

class Question:
    def __init__(self):
        self.c1 = [
            {"question": "What does 'sustainable' mean? (C1)", "answer": "able to continue"},
            {"question": "Complete the word: E_vi_onment (C1)", "answer": "nron"},
        ]
        self.c2 = [
            {"question": "What is the synonym of 'preserve'? (C2)", "answer": "conserve"},
            {"question": "What does 'carbon footprint' mean? (C2)", "answer": "total emissions"},
        ]
        self.cc = [
            {"question": "Name 3 renewable energy sources (CC)", "answer": "solar wind hydro"},
            {"question": "What's the main greenhouse gas? (CC)", "answer": "carbon dioxide"},
        ]

class Game:
    def __init__(self):
        self.player = Player()
        self.questions = Question()
        self.current_enemy = None
        
    def create_enemy(self):
        is_boss = self.player.level % 5 == 0
        health = 2000 if is_boss else 1000
        return {"health": health, "is_boss": is_boss}
    
    def get_random_question(self, category=None):
        if category == "CC":
            return random.choice(self.questions.cc)
        else:
            pool = self.questions.c1*8 + self.questions.c2*3 + self.questions.cc*1
            return random.choice(pool)
    
    def check_answer(self, question):
        user_answer = input("Câu trả lời của bạn: ").strip().lower()
        return user_answer == question["answer"].lower()
    
    def enemy_attack(self, is_boss):
        attack_type = random.choices(["normal", "strong"], weights=[7, 3] if not is_boss else [5, 5])[0]
        
        if is_boss:
            damage = 2 if attack_type == "normal" else 3.5
        else:
            damage = 1 if attack_type == "normal" else 2.5
            
        self.player.hearts -= damage
        print(f"Quái vật sử dụng {attack_type} tấn công! Mất {damage} tim")
        print(f"Máu hiện tại: {self.player.hearts:.1f} ❤️\n")
    
    def check_rare_drop(self):
        if random.random() < 0.0013:
            self.player.add_rare_item()
    
    def show_status(self):
        print(f"\n{'🌟'*10} Tầng {self.player.level} {'🌟'*10}")
        print(f"Tim: {self.player.hearts:.1f} ❤️ | Điểm: {self.player.points} ⭐")
        if self.current_enemy["is_boss"]:
            print(f"BOSS 💀 | Máu: {self.current_enemy['health']}/2000")
        else:
            print(f"Titan ⚔️ | Máu: {self.current_enemy['health']}/1000")
    
    def combat_loop(self):
        self.current_enemy = self.create_enemy()
        
        while self.current_enemy["health"] > 0 and self.player.hearts > 0:
            self.show_status()
            
            # Player's turn
            action = input("Chọn hành động (1-Đánh, 2-Hồi máu, 3-Biến hình): ")
            
            if action == "1":
                question = self.get_random_question()
                print(f"\nCâu hỏi: {question['question']}")
                if self.check_answer(question):
                    damage = self.current_enemy["health"] * 0.75
                    self.current_enemy["health"] -= damage
                    self.player.points += 30
                    print(f"Đánh trúng! Gây {damage:.1f} sát thương!")
                else:
                    print("Trả lời sai! Mất lượt!")
                    
            elif action == "2":
                if self.player.points >= 40:
                    self.player.points -= 40
                    self.player.hearts += 1
                    print("Hồi 1 tim!")
                else:
                    print("Không đủ điểm!")
                    
            elif action == "3":
                if self.player.points >= 250:
                    self.player.points -= 250
                    question = self.get_random_question("CC")
                    print(f"\nCâu hỏi ĐẶC BIỆT: {question['question']}")
                    if self.check_answer(question):
                        reward = random.choice([500, "item"])
                        if reward == "item":
                            self.player.add_rare_item()
                        else:
                            self.player.points += reward
                        print(f"Nhận phần thưởng đặc biệt: {reward}!")
                    else:
                        print("Trả lời sai!")
                else:
                    print("Không đủ điểm!")
                    
            else:
                print("Lựa chọn không hợp lệ!")
                continue
            
            # Check enemy defeat
            if self.current_enemy["health"] <= 0:
                if self.current_enemy["is_boss"]:
                    self.player.points += 300
                print("\n★★★★★ Chiến thắng! ★★★★★")
                self.check_rare_drop()
                return True
            
            # Enemy's turn
            self.enemy_attack(self.current_enemy["is_boss"])
        
        return False
    
    def start(self):
        print("""
        ██████  █████  ██    ██ ███████     ███████  ██████  ██████  
        ██   ██ ██   ██ ██    ██ ██          ██      ██    ██ ██   ██ 
        ██   ██ ███████ ██    ██ █████       █████   ██    ██ ██████  
        ██   ██ ██   ██  ██  ██  ██          ██      ██    ██ ██   ██ 
        ██████  ██   ██   ████   ███████     ██       ██████  ██   ██ 
        """)
        
        while self.player.hearts > 0:
            if not self.combat_loop():
                break
            self.player.level += 1
            input("\nNhấn Enter để tiếp tục...")
        
        print("\nGame Over!")
        print(f"Đạt được cấp độ: {self.player.level}")
        print(f"Vật phẩm hiếm: {', '.join(self.player.items) if self.player.items else 'Không có'}")

if __name__ == "__main__":
    game = Game()
    game.start()