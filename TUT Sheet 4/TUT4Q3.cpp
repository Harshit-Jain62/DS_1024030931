#include <iostream>
using namespace std;

const int SIZE = 10;
int q[SIZE];
int f = -1, r = -1;

void enqueue(int val) {
    if (r == SIZE - 1) {
        cout << "Queue is full" << endl;
        return;
    }
    if (f == -1) f = 0;
    q[++r] = val;
    cout << "Added element: " << val << endl;
}

void dequeue() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Deleted element: " << q[f] << endl;
    if (f == r) {
        f = r = -1;
    } else {
        f++;
    }
}

void isEmpty() {
    if (f == -1) cout << "The queue is empty" << endl;
    else         cout << "The queue is not empty" << endl;
}

void isFull() {
    if (r == SIZE - 1 && f != -1) cout << "The queue is full" << endl;
    else                           cout << "The queue is not full" << endl;
}

void display() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = f; i <= r; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

void interleaveQueue() {
    if (f == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int n = r - f + 1;
    if (n % 2 != 0) {
        cout << "Queue size must be even for interleaving!" << endl;
        return;
    }
    
    int half = n / 2;
    int temp[SIZE];
    int tf = 0, tr = half - 1;
    
    for (int i = 0; i < half; i++) {
        temp[i] = q[f + i];
    }
    
    int index = f;
    for (int i = 0; i < half; i++) {
        q[index++] = temp[i];
        q[index++] = q[f + half + i];
    }
    
    cout << "Queue after interleaving: ";
    display();
}

void displayMenu() {
    cout << "\nQueue Menu\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Check if the queue is empty\n";
    cout << "4. Check if the queue is full\n";
    cout << "5. Display Queue\n";
    cout << "6. Interleave Queue\n";
    cout << "7. Exit\n";
    cout << "Choose: ";
}

int main() {
    int choice, val;
    
    cout << "Initializing queue with sample values: 4 7 11 20 5 9" << endl;
    int sample[] = {4, 7, 11, 20, 5, 9};
    for (int i = 0; i < 6; i++) {
        if (r == SIZE - 1) break;
        if (f == -1) f = 0;
        q[++r] = sample[i];
    }
    display();
    
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
            interleaveQueue();
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