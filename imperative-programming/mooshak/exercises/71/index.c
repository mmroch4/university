#include "binaryTree.h"

int *sumLevels(BTNode *n, int *size, int *sums, int k) {
    sums[k] += n->val;

    if (n->left != NULL) {
        sumLevels(n->left, size, sums, k + 1);
    }

    if (n->right != NULL) {
        sumLevels(n->right, size, sums, k + 1);
    }
}


int *sumTLevels(BTree *t, int *size) {
    if (t->root == NULL) {
        *size = 0;
        return NULL;
    }

    *size = treeHeight(t) + 1;
    
    int *sums = (int *)calloc(*size, sizeof (int));
    
    sumLevels(t->root, size, sums, 0);

    return sums;
}
