#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
using namespace std;

    Node::Node(const string& name, const string& surname, const string& phoneNumber) {
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        next = nullptr;
    }

    LinkedList::LinkedList() {
        head = nullptr;
    }

    void LinkedList::insertAtHead(const string& name, const string& surname, const string& phoneNumber) {
        Node* newNode = new Node(name, surname, phoneNumber);
        newNode->next = head;
        head = newNode;

        cout << "Dodano: " << newNode->name << " " << newNode->surname << ", " << newNode->phoneNumber << endl;
    }

    void LinkedList::deleteByNumber(const string& phoneNumber) {

        // Lista jest pusta
        if (head == nullptr) {
            cout << "Lista jest pusta." << endl;
            return;
        }

        // Node do usuniecia znajduje sie na poczatku listy (head)
        if (head->phoneNumber == phoneNumber) {
            Node* temp = head;
            head = head->next; // Pointer head zostaje ustawiony na kolejny element w liscie
            delete temp; // Zwalnia pamiec zajmowana przez Node
            cout << "Usunieto " << phoneNumber << " z listy." << endl;
            return;
        }

        // Szukanie node'a
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->phoneNumber != phoneNumber) {
            prev = current;
            current = current->next; // Jesli znajdzie nr telefonu, to petla sie konczy
        }                            // W przypadku nie znalezienia, czyli dotarcia do konca (nullptr) metoda jest opuszczana w kolejnym if'ie

        // Nie znaleziono
        if (current == nullptr) {
            cout << "Nie znaleziono " << phoneNumber << " na liscie." << endl;
            return;
        }

        // Usun node
        prev->next = current->next; // Pointer next z ostatniego Node'a omija element do usuniecia, zostajac ustawionym na kolejny Node po current
        delete current; // Zwalnia pamiec zajmowana przez Node
        cout << "Usunieto " << phoneNumber << " z listy." << endl;
    }

    void LinkedList::deleteBySurname(const string& surname) {

        // Lista jest pusta
        if (head == nullptr) {
            cout << "Lista jest pusta." << endl;
            return;
        }

        if (head->surname == surname) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Usunieto " << surname << " z listy." << endl;
            return;
        }

        // Szukanie node'a
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->surname != surname) {
            prev = current;
            current = current->next;
        }

        // Nie znaleziono
        if (current == nullptr) {
            cout << "Nie znaleziono " << surname << " na liscie." << endl;
            return;
        }

        // Usun node
        prev->next = current->next;
        delete current;
        cout << "Usunieto " << surname << " z listy." << endl;
    }

    void LinkedList::printAllNodes() {
        Node* current = head;
        int counter = 1;

        while (current != nullptr) {
            cout << current->name << "," << current->surname << "," << current->phoneNumber << endl;
            current = current->next;
            counter++;
        }
        cout << "---" << endl;
    }

    void LinkedList::saveToFile(const string fileName) {
        ofstream outFile(fileName);

        Node* current = head;
        int counter = 1;

        if (outFile.is_open()) {
            outFile << "Name,Surname,PhoneNumber" << endl;

            while (current != nullptr) {
                outFile << current->name << "," << current->surname << "," << current->phoneNumber << endl;
                current = current->next;
                counter++;
            }
            outFile.close();
            cout << "List saved to " << fileName << endl;
        }
        else {
            cerr << "Blad: nie udalo sie otworzyc pliku.";
        }
    }

    void LinkedList::readFromFile(const string fileName) {
        ifstream inFile(fileName);
        
        if (!inFile.is_open()) {
            cerr << "Blad: nie udalo sie otworzyc " << fileName << " do odczytu." << endl;
            return;
        }

        string line;
        bool isHeader = true;

        while (head != nullptr) { // Czyszczenie listy
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        while (getline(inFile, line)) {
            if (isHeader) {
                isHeader = false;
                continue;
            }

            stringstream ss(line);
            string name, surname, phoneNumber;

            if (getline(ss, name, ',') &&
                getline(ss, surname, ',') &&
                getline(ss, phoneNumber, ',')) {

                // Insert the data into the linked list
                insertAtHead(name, surname, phoneNumber);
            }

        }

        inFile.close();
        cout << "Dane wczytane z " << fileName << endl;
    }

    Node* LinkedList::findByNumber(const string& phoneNumber) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->phoneNumber != phoneNumber) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Nie znaleziono " << phoneNumber << " na liscie." << endl;
            return 0;
        }

        return current;
    }

    Node* LinkedList::findByName(const string& name) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->name != name) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Nie znaleziono " << name << " na liscie." << endl;
            return 0;
        }

        return current;
    }

    Node* LinkedList::findBySurname(const string& surname) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->surname != surname) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Nie znaleziono " << surname << " na liscie." << endl;
            return 0;
        }

        return current;
    }

    Node* LinkedList::modifyName(const string& newName, const string& newSurname, Node* node) {
    
        node->name = newName;
        node->surname = newSurname;
        return node;
    }

    Node* LinkedList::modifyNumber(const string& newNumber, Node* node) {

        node->phoneNumber = newNumber;
        return node;
    }

