#Run this file
from VillianClass import Villain
from WeaponsClass import Weapon
from ShieldsClass import Shield
 ############-------GRU--------###########
gru_weapons = [
        Weapon("Freeze Gun", 50, 11, "Infinite", "Minions occasionally wield freeze ray guns that shoot a freezing beam to immobilize opponents temporarily."),
        Weapon("Electric Prod", 88, 18, 5, "Minions might use electric prods to deliver mild shocks to enemies, stunning them momentarily."),
        Weapon("Mega Magnet", 92, 10, 3, "Minions utilize a mega magnet to attract or repel metal objects, potentially disrupting enemy vehicles or equipment."),
        Weapon("Kalman Missile", 120, 20, 1, "This unavoidable Missile created for enormous distraction")
    ]
gru_shields = [
        Shield("Energy Protected Barrier Gun", 20, 0.40, "Infinite", "The spaceship's shields create an invisible, energy-projected barrier around the vehicle."),
        Shield("Selective Permeability", 50, 0.90, 2, "The shields can be programmed to allow certain objects, signals, or energies to pass through while blocking others.")
    ]
gru = Villain("Gru", gru_weapons, gru_shields)

 ############-------Vector--------#########
vector_weapons = [
        Weapon("Laser Blasters", 70, 15, "Infinite", "Vector's specialized weapons that fire laser beams to deal substantial damage."),
        Weapon("Plasma Grenades",56,13,8,"Vector could use plasma grenades that explode on impact, releasing fiery energy bursts that deal significant damage to enemy vehicles caught in the blast radius."),
        Weapon("Sonic Reonance",100,22,3,"Fires powerful sonic waves that can shatter enemy shields and disrupt their systems, temporarily incapacitating them.")
    ]

vector_shields = [
        Shield("Energy Net Trap", 15, 0.32, "Infinite", "Vector's pod might have the ability to deploy an energy net that ensnares enemy vehicles."),
        Shield("Quantum Deflector", 40, 0.8, 3, "Manipulates quantum states to create a deflection field, causing enemy projectiles to miss the spaceship by a slight margin.")
    ]
vector = Villain("Vector", vector_weapons, vector_shields)

############--------GAME-------#########
round_number = 1
while gru.health > 0 and vector.health > 0:
    print(f"Round {round_number}")
    gru.choose_action(vector)
    vector.choose_action(gru)
    print(f"{gru.name} Health: {gru.health:.2f}, {vector.name} Health: {vector.health:.2f}\n")
    round_number += 1

if gru.health <= 0:
    print(f"{vector.name} wins!")
else:
    print(f"{gru.name} wins!")
