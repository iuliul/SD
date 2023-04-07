from UI import Console
from masina_repository import Masina_repository

if __name__ == '__main__':
    masina_repository = Masina_repository('masini')
    console = Console(masina_repository)
    console.run_menu()
