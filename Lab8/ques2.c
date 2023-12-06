#include <stdio.h>

void iOrder(char tree[], int size, int index) {
    if (index < size && tree[index] != '\0') {
        iOrder(tree, size, 2 * index + 1);
        printf("%c ", tree[index]);
        iOrder(tree, size, 2 * index + 2); 
    }
}

void PreOrder(char tree[], int size, int index) {
    if (index < size && tree[index] != '\0') {
        printf("%c ", tree[index]);

        PreOrder(tree, size, 2 * index + 1);
        PreOrder(tree, size, 2 * index + 2); 
    }
}

void PostOrder(char tree[], int size, int index) {
    if (index < size && tree[index] != '\0') {
        PostOrder(tree, size, 2 * index + 1);
        PostOrder(tree, size, 2 * index + 2);
        printf("%c ", tree[index]); 
    }
}

int main() {
    char binaryTree[] = {'A', 'B', 'C', 'D', '\0', 'E', 'F', '\0', '\0', '\0', '\0', 'G', 'H', '\0', '\0', '\0'};
    int treeSize = sizeof(binaryTree) / sizeof(binaryTree[0]);

    printf("Inorder: ");
    iOrder(binaryTree, treeSize, 0);

    printf("\nPreorder: ");
    PreOrder(binaryTree, treeSize, 0);

    printf("\nPostorder: ");
    PostOrder(binaryTree, treeSize, 0);

    return 0;
}
