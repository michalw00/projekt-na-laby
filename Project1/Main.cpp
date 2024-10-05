#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;

    int option;
    string name, phoneNumber;
    const string fileName = "lista.txt";

    while (true) {
        cout << "1: Dodaj \n";
        cout << "2: Usun \n";
        cout << "3: Zmien \n";
        cout << "4: Wyswietl\n";
        cout << "5: Zapisz do pliku\n";
        cout << "0: Wyjdz\n";
        cout << "Wybierz opcje: ";
        cin >> option;

        cin.ignore();

        cout << endl << endl << endl;

        switch (option) {
            case 1: // Add
                cout << "Podaj imie i nazwisko: ";
                getline(cin, name);
                cout << "Podaj numer telefonu: ";
                getline(cin, phoneNumber);
                list.insertAtHead(name, phoneNumber);
                break;
            case 2: // Delete
                cout << "Podaj numer telefonu: ";
                getline(cin, phoneNumber);
                list.deleteByNumber(phoneNumber);
            break;
            case 3: // Modify
            {
                Node* foundNode;
                string numberToFind;
                cout << "Wprowadz numer telefonu osoby ktora chcesz zmienic: ";
                cin >> numberToFind;
                foundNode = list.findByNumber(numberToFind);

                cout << "1: Zmien imie \n";
                cout << "2: Zmien numer telefonu \n";
                cout << "Wybierz opcje: ";
                cin >> option;

                string newName;
                switch (option) {
                case 1:
                    cout << "Wprowadz nowe imie: ";
                    cin >> newName;
                    list.modifyName(newName, foundNode);
                    break;
                case 2:
                    cout << "Wprowadz nowy numer telefonu: ";
                    cin >> newName;
                    list.modifyName(newName, foundNode);
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
            case 0: // Quit
                return 0;
            default:
                cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }

    }

    return 0;
}