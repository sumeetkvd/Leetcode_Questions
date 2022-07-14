Construct Binary Tree from Preorder and Inorder Traversal: -


The solution in C: -


int *g_preorder;
int g_preorderSize;
int *g_inorder;
int g_inorderSize;
int g_index[10000];
int g_preIndex = 0;
void buildChildTree(int inStart, int inEnd, struct TreeNode **root) {

    if (g_preIndex >= g_inorderSize) {
        return;
    }
    *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int val = g_preorder[g_preIndex];
    (*root)->val = val;
    (*root)->left = NULL;
    (*root)->right = NULL;
    if (g_index[val + 3000] > inStart) {
        (g_preIndex) += 1;
        buildChildTree(inStart, g_index[val + 3000] - 1, &((*root)->left));
    }
    if(g_index[val + 3000] < inEnd) {
        (g_preIndex) += 1;
        buildChildTree(g_index[val + 3000] + 1, inEnd , &((*root)->right));
    }

    
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode *root;
    int preIndex = 0;
    if (preorderSize == 0) {
        return NULL;
    }
    for (int i = 0; i < inorderSize; i++) {
        g_index[inorder[i] + 3000] = i;
    }
    g_preorder = preorder;
    g_preorderSize = preorderSize;
    g_inorder = inorder;
    g_inorderSize = inorderSize;
    g_preIndex = 0;
    buildChildTree(0, inorderSize - 1, &root);
    return root;
}




