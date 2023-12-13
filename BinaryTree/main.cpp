#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
void insert(Node<T>*& root, T data) {
    if (root == nullptr) {
        root = new Node<T>(data);
    } else if (data <= root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

template <typename T>
void preorder(Node<T>* root) {
    if (root == nullptr) return;
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void inorder(Node<T>* root) {
    if (root == nullptr) return;
    inorder(root->left);
    inorder(root->right);
}

template <typename T>
void postorder(Node<T>* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
}
