class Shield:
    def __init__(self, name, energy, save, resources, description):
        self.name = name
        self.energy = energy
        self.save = save
        self.resources = resources
        self.description = description

    def apply_shield(self, damage):
        damage_reduction = damage * self.save
        remaining_damage = damage - damage_reduction
        return remaining_damage

# class GruShielda(Shields):
#     def __init__(self,energy,save,resources,description):
#         super().__init__(energy, save, resources, description)

# class VectorShields(Shields):
#     def __init__(self,energy,save,resources,description):
#         super().__init__(energy, save, resources, description)
