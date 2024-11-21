#include <iostream>
#include <algorithm> // Для std::max

struct Node {
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// Получение высоты узла
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Пересчёт высоты узла
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

// Поворот вправо
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Поворот влево
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Получение баланса узла
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Вставка в АВЛ-дерево
Node* insert(Node* node, int value) {
    if (!node) {
        return new Node(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node; // Дубликаты не вставляются
    }

    updateHeight(node);

    int balance = getBalance(node);

    // Левое левое
    if (balance > 1 && value < node->left->value) {
        return rotateRight(node);
    }

    // Правое правое
    if (balance < -1 && value > node->right->value) {
        return rotateLeft(node);
    }

    // Левое правое
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Правое левое
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Проверка сбалансированности дерева
bool isBalanced(Node* node) {
    if (!node) return true;

    int balance = getBalance(node);

    return std::abs(balance) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

// Освобождение памяти
void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

int main() {
    Node* root = nullptr;
    int value;

    std::cout << "Введите последовательность чисел, оканчивающуюся нулем: ";
    while (std::cin >> value && value != 0) {
        root = insert(root, value);
    }

    if (isBalanced(root)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    freeTree(root);
    return 0;
}
