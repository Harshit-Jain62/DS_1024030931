#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool checkBST(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    return checkBST(root->left, min, root->data) && 
           checkBST(root->right, root->data, max);
}

bool isBST(Node* root) {
    return checkBST(root, -100000, 100000);
}

int main() {
    Node* root1 = new Node{5, new Node{3, NULL, NULL}, new Node{7, NULL, NULL}};
    Node* root2 = new Node{5, new Node{7, NULL, NULL}, new Node{3, NULL, NULL}};
    
    cout << isBST(root1) << endl;
    cout << isBST(root2) << endl;
    
    return 0;
}