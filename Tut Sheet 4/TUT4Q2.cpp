#include <iostream>
using namespace std;

const int SIZE = 10;
int q[SIZE];
int f = -1, r = -1;

void enqueue(int val) {
    if ((r + 1) % SIZE == f) {
        cout << "Queue is full" << endl;
        return;
    }
    if (f == -1) { // first element
        f = r = 0;
    } else {
        r = (r + 1) % SIZE;
    }
    q[r] = val;
    cout << "Added element: " << val << endl;
}

void dequeue() {
    if (f == -1) { // empty
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Deleted element: " << q[f] << endl;
    if (f == r) {
        // last element removed -> reset
        f = r = -1;
    } else {
        f = (f + 1) % SIZE;
    }
}

void isEmpty() {
    if (f == -1) cout << "The queue is empty" << endl;
    else         cout << "The queue is not empty" << endl;
}

void isFull() {
    if ((r + 1) % SIZE == f) cout << "The queue is full" << endl;
    else                      cout << "The queue is not full" << endl;
}

void peek() {
    if (f == -1) {
        cout << "Queue is empty, cannot peek" << endl;
    } else {
        cout << "Front element: " << q[f] << endl;
    }
}

void display() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = f;
    while (true) {
        cout << q[i] << " ";
        if (i == r) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

void displayMenu() {
    cout << "\nCircular Queue Menu\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Check if the queue is empty\n";
    cout << "4. Check if the queue is full\n";
    cout << "5. Display Queue\n";
    cout << "6. Peek (view front element)\n";
    cout << "7. Exit\n";
    cout << "Choose: ";
}

int main() {
    int choice, val;
    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            enqueue(val);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            isEmpty();
        }
        else if (choice == 4) {
            isFull();
        }
        else if (choice == 5) {
            display();
        }
        else if (choice == 6) {
            peek();
        }
        else if (choice == 7) {
            cout << "You have exited the menu" << endl;
            break;
        }
        else {
            cout << "Enter a valid menu option" << endl;
        }
    }
    return 0;
}