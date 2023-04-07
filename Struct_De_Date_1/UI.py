from masina_repository import Masina_repository


class Console:
    def __init__(self, masina_repository: Masina_repository):
        self.masina_repository = masina_repository

    def run_menu(self):
        while True:
            optiune = input("Introduceti optiunea: ")
            array = optiune.split()
            if array[0] == "SEARCH":
                token = array[1]
                print(self.masina_repository.cautare_secventiala(token))
                lista_sortata = self.masina_repository.sortare(self.masina_repository.get_all(), 'tokenMasina')
                self.masina_repository.cautare_binara(lista_sortata, 0, len(lista_sortata) - 1, token)

            elif array[0] == "SORT":
                token = ' '.join(array[1:])
                n = len(self.masina_repository.get_all())
                lista = self.masina_repository.sortare(self.masina_repository.get_all(), token)
                print(*lista, sep ='\n')
                self.masina_repository.quick_sort(self.masina_repository.get_all(), 0, n - 1, array[1])
                print(*lista, sep ='\n')
            else:
                print("Optiune gresita, reincercati!")
