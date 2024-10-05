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
    string phoneNumber;
    Node* next;

    Node(const string&, const string&, Node*);

    Node(const string &name, const string &phoneNumber);
};

class LinkedList {
public:
    LinkedList();

    void loopNodes();

    void insertAtHead(const string& name, const string& phoneNumber);

    void deleteByNumber(const string& number);

    void printAllNodes();

    void saveToFile(const string fileName);

    Node* findByNumber(const string& phoneNumber);

    Node* findByName(const string& name);

    Node* modifyName(const string& newName, Node* node);

    Node* modifyNumber(const string& newNumber, Node* node);


private:
Node* head;

};

#endif //LINKEDLIST_H
