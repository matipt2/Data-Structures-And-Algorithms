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
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void inorder(Node<T>* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

template <typename T>
void postorder(Node<T>* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main() {
    Node<int>* root = nullptr;
    insert(root, 12);
    insert(root, 4);
    insert(root, 7);
    insert(root, 25);
    insert(root, 8);
    insert(root, 11);

    std::cout << "Preorder: ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Inorder: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Postorder: ";
    postorder(root);
    std::cout << "\n";

    insert(root, 40);
    insert(root, 3);
    insert(root, 14);

    std::cout << "Preorder po dodaniu: ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Inorder po dodaniu: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Postorder po dodaniu: ";
    postorder(root);
    std::cout << "\n";

    return 0;
}
