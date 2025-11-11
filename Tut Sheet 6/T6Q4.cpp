#include<iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() { 
        head = NULL;
        tail = NULL;
    }

    void insert(char val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (head == NULL) return true;
        
        Node* front = head;
        Node* back = tail;
        
        while (front != back && front->prev != back) {
            if (front->data != back->data) {
                return false;
            }
            front = front->next;
            back = back->prev;
        }
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll1, dll2, dll3;
    
    // Test case 1: Palindrome
    dll1.insert('r');
    dll1.insert('a');
    dll1.insert('d');
    dll1.insert('a');
    dll1.insert('r');
    
    // Test case 2: Not palindrome
    dll2.insert('h');
    dll2.insert('e');
    dll2.insert('l');
    dll2.insert('l');
    dll2.insert('o');
    
    // Test case 3: Single character
    dll3.insert('a');

    cout << "List 1: ";
    dll1.display();
    cout << "Is palindrome: " << (dll1.isPalindrome() ? "Yes" : "No") << endl;
    
    cout << "\nList 2: ";
    dll2.display();
    cout << "Is palindrome: " << (dll2.isPalindrome() ? "Yes" : "No") << endl;
    
    cout << "\nList 3: ";
    dll3.display();
    cout << "Is palindrome: " << (dll3.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}