#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* head = NULL;

int main() {
    int choice, value, target;
    
    while(true) {
        cout << "\n1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before\n";
        cout << "4. Insert after\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search node\n";
        cout << "9. Display\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at beginning\n";
        }
        else if(choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = NULL;
            
            if(head == NULL) {
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "Inserted " << value << " at end\n";
        }
        else if(choice == 3) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter target: ";
            cin >> target;
            
            if(head == NULL) {
                cout << "List empty\n";
                continue;
            }
            
            if(head->value == target) {
                Node* newNode = new Node();
                newNode->value = value;
                newNode->next = head;
                head = newNode;
                cout << "Inserted " << value << " before " << target << endl;
                continue;
            }
            
            Node* temp = head;
            while(temp->next != NULL && temp->next->value != target) {
                temp = temp->next;
            }
            
            if(temp->next == NULL) {
                cout << "Node " << target << " not found\n";
            } else {
                Node* newNode = new Node();
                newNode->value = value;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " before " << target << endl;
            }
        }
        else if(choice == 4) {
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter target: ";
            cin >> target;
            
            if(head == NULL) {
                cout << "List empty\n";
                continue;
            }
            
            Node* temp = head;
            while(temp != NULL && temp->value != target) {
                temp = temp->next;
            }
            
            if(temp == NULL) {
                cout << "Node " << target << " not found\n";
            } else {
                Node* newNode = new Node();
                newNode->value = value;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted " << value << " after " << target << endl;
            }
        }
        else if(choice == 5) {
            if(head == NULL) {
                cout << "List empty\n";
            } else {
                cout << "Deleted " << head->value << " from beginning\n";
                head = head->next;
            }
        }
        else if(choice == 6) {
            if(head == NULL) {
                cout << "List empty\n";
            } else if(head->next == NULL) {
                cout << "Deleted " << head->value << " from end\n";
                head = NULL;
            } else {
                Node* temp = head;
                while(temp->next->next != NULL) {
                    temp = temp->next;
                }
                cout << "Deleted " << temp->next->value << " from end\n";
                temp->next = NULL;
            }
        }
        else if(choice == 7) {
            cout << "Enter value to delete: ";
            cin >> value;
            
            if(head == NULL) {
                cout << "List empty\n";
            } else if(head->value == value) {
                cout << "Deleted " << head->value << endl;
                head = head->next;
            } else {
                Node* temp = head;
                while(temp->next != NULL && temp->next->value != value) {
                    temp = temp->next;
                }
                
                if(temp->next == NULL) {
                    cout << "Node " << value << " not found\n";
                } else {
                    cout << "Deleted " << temp->next->value << endl;
                    temp->next = temp->next->next;
                }
            }
        }
        else if(choice == 8) {
            cout << "Enter value to search: ";
            cin >> value;
            
            if(head == NULL) {
                cout << "List empty\n";
            } else {
                Node* temp = head;
                int position = 1;
                bool found = false;
                
                while(temp != NULL) {
                    if(temp->value == value) {
                        cout << "Found " << value << " at position " << position << endl;
                        found = true;
                        break;
                    }
                    temp = temp->next;
                    position++;
                }
                
                if(!found) {
                    cout << "Node " << value << " not found\n";
                }
            }
        }
        else if(choice == 9) {
            if(head == NULL) {
                cout << "List empty\n";
            } else {
                Node* temp = head;
                while(temp != NULL) {
                    cout << temp->value << " -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
        else if(choice == 10) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}