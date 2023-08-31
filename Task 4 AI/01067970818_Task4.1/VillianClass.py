import random

class Villain:
    def __init__(self, name, weapons, shields):
        self.name = name
        self.health = 100
        self.energy = 500
        self.shield = None
        self.weapons = weapons
        self.shields = shields

    def choose_action(self, opponent):
        action = random.choice(["attack", "shield"])
        if action == "attack":
            self.attack(opponent)
        else:
            self.use_shield()

    def attack(self, opponent):
        weapon = random.choice(self.weapons)
        damage = weapon.damage
        if opponent.shield:
            damage = opponent.shield.apply_shield(damage)
        opponent.health -= damage
        print(f"{self.name} attacks {opponent.name} with {weapon.name} for {damage:.2f} damage.")

    def use_shield(self):
        if self.shields:
            shield = random.choice(self.shields)
            self.shield = shield
            self.energy -= shield.energy
            print(f"{self.name} uses {shield.name}.")


