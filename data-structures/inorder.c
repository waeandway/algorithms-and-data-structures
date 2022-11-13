#include <stdio.h>
#include <stdlib.h>

int inorder_count = 0;
/*--------------------------------------*/
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;
/*--------------------------------------*/
void inorder(TreeNode* node) {
    printf("inorder 호출 횟수 %d회\n", ++inorder_count);
    if (node != NULL) {
        printf("(%d)->left = %d\n",node->data, node->left);
        inorder(node->left);
        printf("root의 주소 = %d, 값 = %d\n", node, node->data);
        printf("node->right(%d)로 이동\n", node->right);
        inorder(node->right);
        printf("\n");
        }
}
/*--------------------------------------*/
int main(void)
{
    TreeNode n1={1, NULL, NULL};
    TreeNode n2={2, NULL, NULL};
    TreeNode n3={"*", &n1, &n2};
    TreeNode n4={3, NULL, NULL};
    TreeNode n5={"-", &n3, &n4};
    TreeNode n6={4, NULL, NULL};
    TreeNode n7={"+", &n5, &n6};
    TreeNode *root = &n7;
    inorder(root);
}