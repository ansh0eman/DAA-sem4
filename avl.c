#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *root, int key) {
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    if (root == NULL) {
        return newNode;
    }

    AVLNode *current = root;
    AVLNode *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    AVLNode *unbalancedNode = NULL;
    current = root;

    while (current != NULL) {
        int balance = getBalance(current);

        if (balance > 1 && key < current->left->key) {
            unbalancedNode = current;
            current = rightRotate(current);
        } else if (balance < -1 && key > current->right->key) {
            unbalancedNode = current;
            current = leftRotate(current);
        } else if (balance > 1 && key > current->left->key) {
            unbalancedNode = current;
            current->left = leftRotate(current->left);
            current = rightRotate(current);
        } else if (balance < -1 && key < current->right->key) {
            unbalancedNode = current;
            current->right = rightRotate(current->right);
            current = leftRotate(current);
        }

        if (current == unbalancedNode) {
            break;
        }

        current->height = 1 + max(height(current->left), height(current->right));

        if (current->left != NULL) {
            current->left->height = 1 + max(height(current->left->left), height(current->left->right));
        }

        if (current->right != NULL) {
            current->right->height = 1 + max(height(current->right->left), height(current->right->right));
        }

        if (current->left != NULL && current->right != NULL) {
            current->height = 1 + max(height(current->left), height(current->right));
        }
    }

    return current;
}

AVLNode *minValueNode(AVLNode *node) {
    AVLNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

AVLNode *search(AVLNode *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

AVLNode *predecessor(AVLNode *root, int key) {
    AVLNode *pred = NULL;
    AVLNode *current = root;

    while (current != NULL) {
        if (current->key >= key) {
            current = current->left;
        } else {
            pred = current;
            current = current->right;
        }
    }

    return pred;
}

AVLNode *successor(AVLNode *root, int key) {
    AVLNode *succ = NULL;
    AVLNode *current = root;

    while (current != NULL) {
        if (current->key <= key) {
            current = current->right;
        } else {
            succ = current;
            current = current->left;
        }
    }

    return succ;
}

void inorder(AVLNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    AVLNode *root = NULL;
    int keys[] = {30, 20, 40, 10, 25, 35, 50};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    printf("Inorder traversal of AVL tree: ");
    inorder(root);
    printf("\n");

    int key = 25;
    AVLNode *pred = predecessor(root, key);
    AVLNode *succ = successor(root, key);

    if (pred != NULL) {
        printf("Predecessor of %d is %d\n", key, pred->key);
    } else {
        printf("No predecessor for %d\n", key);
    }

    if (succ != NULL) {
        printf("Successor of %d is %d\n", key, succ->key);
    } else {
        printf("No successor for %d\n", key);
    }

    return 0;
}
