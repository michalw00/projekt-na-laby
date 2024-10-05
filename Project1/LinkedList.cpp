#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

    Node::Node(const string& name, const string& phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        next = nullptr;
    }

    LinkedList::LinkedList() {
        head = nullptr;
    }

    void LinkedList::loopNodes() {

    }

    void LinkedList::insertAtHead(const string& name, const string& phoneNumber) {
        Node* newNode = new Node(name, phoneNumber);
        newNode->next = head;
        head = newNode;

        cout << "Dodano: " << newNode->name << ", " << newNode->phoneNumber << endl;
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

    void LinkedList::printAllNodes() {
        Node* current = head;
        int counter = 1;

        while (current != nullptr) {
            cout << counter << "| imie: " << current->name << ", nr.: " << current->phoneNumber << endl;
            current = current->next;
            counter++;
        }
        cout << "___________________" << endl;
    }

    void LinkedList::saveToFile(const string fileName) {
        std::ofstream outFile(fileName);

        Node* current = head;
        int counter = 1;

        if (outFile.is_open()) {
            while (current != nullptr) {
                outFile << counter << "| imie: " << current->name << ", nr.: " << current->phoneNumber << endl;
                current = current->next;
                counter++;
            }
            outFile.close();
            cout << "___________________" << endl;
        }
        else {
            std::cerr << "Blad: nie udalo sie otworzyc pliku";
        }
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

    Node* LinkedList::modifyName(const string& newName, Node* node) {
    
        node->name = newName;
        return node;
    }

    Node* LinkedList::modifyNumber(const string& newNumber, Node* node) {

        node->phoneNumber = newNumber;
        return node;
    }

