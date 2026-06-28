#include "binaryTree.h"

int numberLeafs(BTNode *n) {
    if (n->left == NULL && n->right == NULL) {
        return 1;
    }

    int count = 0;

    if (n->left != NULL) {
        count += numberLeafs(n->left);
    }

    if (n->right != NULL) {
        count += numberLeafs(n->right);
    }

    return count;
}

int numberTLeafs(BTree *t) {
    return numberLeafs(t->root);
}
