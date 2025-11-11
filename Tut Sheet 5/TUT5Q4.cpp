#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head = NULL;

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    
    for(int i = n-1; i >= 0; i--) {
        Node* newNode = new Node();
        newNode->value = arr[i];
        newNode->next = head;
        head = newNode;
    }
    
    cout << "Original: ";
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
    cout << "Reversed: ";
    temp = head;
    while(temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
    
    return 0;
}