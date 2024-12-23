#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update the height of a node
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

// Right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert a new key into the AVL tree
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node; // Duplicate keys are not allowed in AVL tree
    }

    updateHeight(node);

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// In-order traversal of the AVL tree
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;
    int values[] = { 17, 23, 201, 93, 67, 83, 13, 23, 10, 191, 84, 58 };

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "In-order traversal of the AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
