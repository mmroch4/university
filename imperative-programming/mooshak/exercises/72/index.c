#include "binaryTree.h"

BTNode *findNode(BTNode *n, NodeInfo val) {
    if (n == NULL) return NULL;
    
    if (n->val == val) return n;

    return val <= n->val ? findNode(n->left, val) : findNode(n->right, val); 
}

int nodeBalance(BTNode *n, NodeInfo val) { 
    if (n == NULL) return 0;

    return height(n->right) - height(n->left);  
}

int treeBalance(BTree *t, NodeInfo val) {
    if (t->root == NULL) return 0;

    BTNode *node = findNode(t->root, val);

    return nodeBalance(node, val);
}
