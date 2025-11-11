#include<iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

bool searchRecursive(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

bool searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

int findMax(Node* root) {
    while (root->right != NULL) root = root->right;
    return root->data;
}

int findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root->data;
}

Node* findNode(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* findSuccessor(Node* root, int key) {
    Node* current = findNode(root, key);
    if (current == NULL) return NULL;
    if (current->right != NULL) {
        Node* temp = current->right;
        while (temp->left != NULL) temp = temp->left;
        return temp;
    }
    Node* successor = NULL;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

Node* findPredecessor(Node* root, int key) {
    Node* current = findNode(root, key);
    if (current == NULL) return NULL;
    if (current->left != NULL) {
        Node* temp = current->left;
        while (temp->right != NULL) temp = temp->right;
        return temp;
    }
    Node* predecessor = NULL;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Search 40 (Recursive): " << searchRecursive(root, 40) << endl;
    cout << "Search 40 (Non-Recursive): " << searchNonRecursive(root, 40) << endl;
    cout << "Search 90 (Recursive): " << searchRecursive(root, 90) << endl;
    cout << "Max: " << findMax(root) << endl;
    cout << "Min: " << findMin(root) << endl;

    Node* succ = findSuccessor(root, 40);
    if (succ != NULL) cout << "Inorder successor of 40: " << succ->data << endl;
    else cout << "No successor found for 40" << endl;

    Node* pred = findPredecessor(root, 40);
    if (pred != NULL) cout << "Inorder predecessor of 40: " << pred->data << endl;
    else cout << "No predecessor found for 40" << endl;

    return 0;
}