//
// Created by wmich on 04.10.2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

class Node {
public:
    string name;
    string surname;
    string phoneNumber;
    Node* next;

    Node(const string &name, const string& surname, const string &phoneNumber);
};

class LinkedList {
public:
    LinkedList();

    void insertAtHead(const string& name, const string& surname, const string& phoneNumber);

    void deleteByNumber(const string& number);

    void deleteBySurname(const string& surname);

    void printAllNodes();

    void saveToFile(const string fileName);

    void readFromFile(const string fileName);

    Node* findByNumber(const string& phoneNumber);

    Node* findByName(const string& name);

    Node* findBySurname(const string& surname);

    Node* modifyName(const string& newName, const string& newSurname, Node* node);

    Node* modifyNumber(const string& newNumber, Node* node);


private:
Node* head;

};

#endif //LINKEDLIST_H
