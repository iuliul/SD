from entities import Masina
from functools import wraps
import time

class Masina_repository:
    def __init__(self, file_name):
        self.lista_masini = []
        self.file_name = file_name
        self.load_data()

    def get_all(self):
        return self.lista_masini

    @staticmethod
    def timer(func):
        @wraps(func)
        def wrapper(*args):
            start_time = time.time()
            retval = func(*args)
            print("the function ends in ", time.time() - start_time, "secs")
            return retval

        return wrapper

    def load_data(self):
        with open(self.file_name) as f:
            for line in f:
                array = line.split()
                marca = array[0]
                model = array[1]
                token = array[2]
                achizitie = array[3]
                vanzare = array[4]
                masina = Masina(marca, model, token, int(achizitie), int(vanzare))
                self.lista_masini.append(masina)

    @timer
    def cautare_secventiala(self, token):
        for i in range(len(self.lista_masini)):
            if self.lista_masini[i].tokenMasina == token:
                return self.lista_masini[i]

    @timer
    def cautare_binara(self, lista, left, right, token):
        if left <= right:
            mid = (left + right)//2
            if lista[mid].tokenMasina == token:
                return lista[mid]
            elif lista[mid].tokenMasina < token:
                return Masina_repository.cautare_binara(self, lista, mid + 1, right, token)
            else:
                return Masina_repository.cautare_binara(self, lista, left, mid - 1, token)
        else:
            return -1


    @timer
    def sortare(self, lista, comparator):
        comparator = comparator.split()
        for i in range(len(lista) - 1):
            for j in range(i + 1, len(lista)):
                if lista[i].__getattribute__(comparator[0]) > lista[j].__getattribute__(comparator[0]):
                    lista[i], lista[j] = lista[j], lista[i]
                elif lista[i].__getattribute__(comparator[0]) == lista[j].__getattribute__(comparator[0]) and len(comparator) > 1:
                    if lista[i].__getattribute__(comparator[1]) > lista[j].__getattribute__(comparator[1]):
                        lista[i], lista[j] = lista[j], lista[i]
        return lista

    @staticmethod
    def pivot_calculator(lista, left, right, comparator):
        pivot = lista[right]
        i = left - 1
        for j in range(left, right):
            if lista[j].__getattribute__(comparator) < pivot.__getattribute__(comparator):
                i += 1
                lista[i], lista[j] = lista[j], lista[i]
        i += 1
        lista[i], pivot = pivot, lista[i]
        return i

    @timer
    def quick_sort(self, lista, left, right, comparator):
        if left < right:
            pivot_index = Masina_repository.pivot_calculator(lista, left, right, comparator)
            Masina_repository.quick_sort(self, lista, left, pivot_index - 1, comparator)
            Masina_repository.quick_sort(self, lista, pivot_index + 1, right, comparator)