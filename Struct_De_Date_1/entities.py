from dataclasses import dataclass


@dataclass
class Masina:
    marca: str
    model: str
    tokenMasina: str
    pretAchizitie: int
    pretVanzare: int

    # @property
    # def get_tokenMasina(self):
    #     return self.__tokenMasina

    def __str__(self):
        return f'{self.marca} {self.model} {self.tokenMasina} {self.pretAchizitie} {self.pretVanzare}'

