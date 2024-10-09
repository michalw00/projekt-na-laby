#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;

    int option;
    string name, surname, phoneNumber;
    const string fileName = "lista.txt";

    while (true) {
        cout << "1: Dodaj \n";
        cout << "2: Usun \n";
        cout << "3: Zmien \n";
        cout << "4: Wyswietl\n";
        cout << "5: Zapisz do pliku\n";
        cout << "6: Odczytaj z pliku\n";
        cout << "0: Wyjdz\n";
        cout << "Wybierz opcje: ";
        cin >> option;

        cin.ignore();

        cout << endl << endl << endl;

        switch (option) {
            case 1: // Add
                cout << "Wprowadz imie: ";
                cin >> name;
                cout << "Wprowadz nazwisko: ";
                cin >> surname;
                cout << "Podaj numer telefonu: ";
                cin >> phoneNumber;
                list.insertAtHead(name, surname, phoneNumber);
                break;
            case 2: // Delete
                cout << "Wprowadz nazwisko: ";
                cin >> surname;
                list.deleteBySurname(surname);
            break;
            case 3: // Modify
            {
                Node* foundNode;
                string surnameToFind;
                cout << "Wprowadz nazwisko osoby ktora chcesz zmienic: ";
                cin >> surnameToFind;
                foundNode = list.findBySurname(surnameToFind);

                cout << "1: Zmien imie i nazwisko\n";
                cout << "2: Zmien numer telefonu \n";
                cout << "Wybierz opcje: ";
                cin >> option;

                string newName;
                string newSurname;
                string newNumber;
                switch (option) {
                case 1:
                    cout << "Wprowadz nowe imie: ";
                    cin >> newName;
                    cout << "Wprowadz nowe nazwisko: ";
                    cin >> newSurname;
                    list.modifyName(newName, newSurname, foundNode);
                    break;
                case 2:
                    cout << "Wprowadz nowy numer telefonu: ";
                    cin >> newNumber;
                    list.modifyNumber(newNumber, foundNode);
                    break;
                }

            } break;
            case 4: // Print
                list.printAllNodes();
                break;
            case 5: // Save
                list.saveToFile(fileName);
                cout << "Zapisano do lista.txt" << endl;
                break;
            case 6:
                list.readFromFile(fileName);
                break;
            case 0: // Quit
                return 0;
            default:
                cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }

    }

    return 0;
}