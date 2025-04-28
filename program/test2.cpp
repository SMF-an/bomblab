// this program is to test secret_phase

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef long long ElemType;
typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

BTNode* CreateBTree(ElemType a[], int i, int n)
{
    if (i > n)
        return NULL;
    if (a[i] == 0)
        return NULL;
    BTNode* b = (BTNode*)malloc(sizeof(BTNode));
    b->data = a[i];
    b->lchild = CreateBTree(a, i * 2, n);
    b->rchild = CreateBTree(a, i * 2 + 1, n);
    return b;
}

void DestroyBTree(BTNode*& b)
{
    if (b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

int FindNode(BTNode* b, ElemType x)
{
    if (b == NULL)
        return -1;
    else if (x < b->data)
        return FindNode(b->lchild, x) * 2;
    else if (x > b->data)
        return FindNode(b->rchild, x) * 2 + 1;
    else
        return 0;
}

void DispBTree(BTNode* b)
{
    if (b != NULL)
    {
        printf("%d", b->data);
        if (b->lchild != NULL || b->rchild != NULL)
        {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != NULL)
                printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

int main()
{
    ElemType a[20] = {0, 36, 8, 50, 6, 22, 45, 107, 1, 7, 20, 35, 40, 47, 99, 1001};
    int n = 15;
    BTNode* b = CreateBTree(a, 1, n);
    DispBTree(b);

    ElemType target = 7;
    int result = FindNode(b, target);
    printf("\nThe result is: %d", result);
    DestroyBTree(b);
    return 0;
}