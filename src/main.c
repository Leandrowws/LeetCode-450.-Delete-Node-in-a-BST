#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* Insert(struct TreeNode *root, int val) {
    if(root==NULL) {
        struct TreeNode *aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->right = NULL;
        aux->left = NULL;
        aux->val = val;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Insert(root->left, val);
        } else {
            root->right = Insert(root->right, val);
        }
        return root;
    }
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root==NULL) {
        return NULL;
    } 
        if(root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            } else {
                if(root->left != NULL && root->right != NULL) {
                    struct TreeNode *aux = root->left;
                    while(aux->right != NULL) {
                        aux = aux->right;
                    }
                    root->val = aux->val;
                    aux->val = key;
                    root->left = deleteNode(root->left, key);
                    return root;
                } else {
                    struct TreeNode *aux;
                    if(root->left != NULL) {
                        aux = root->left;
                    } else {
                        aux = root->right;
                    }
                    free(root);
                    return aux;
                }
            }
            } else {
                if(key < root->val) {
                    root->left = deleteNode(root->left, key);
                } else {
                    root->right = deleteNode(root->right, key);
                }
            }
            return root;
 }
    
void Imprimir(struct TreeNode *root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int main() {

    struct TreeNode *arv = NULL;
    
    for(int i = 0; i < 10; i++) {
        arv = Insert(arv, i);
    }
    printf("\nAntes de remover:\n\t");
    Imprimir(arv);
    printf("\n");

    arv = deleteNode(arv, 5);

    printf("Depois de remover: \n\t");
    Imprimir(arv);
    printf("\n\n");

    return 0;
}
