#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct treenode
{
    int weight;
    struct treenode* left;
    struct treenode* right;
}treenode;
typedef treenode* bitree;

int wplcaulculate(bitree T)
{
    if(T == NULL)
    {
        return 0;
    }
    int front =0;
    int rear =0;
    int wpl =0;
    int depth =0;
    bitree queue[MAXSIZE];
    queue[rear]=T;
    rear++;
    while(rear!=front)
    {
        int count=rear-front;
        while(count>0)
        {
            bitree curr=queue[front];
            front++;
            if(curr->left==NULL && curr->right==NULL)
            {
                wpl=depth*curr->weight+wpl;
            }
            if(curr->left!=NULL)
            {
                queue[rear]=curr->left;
                rear++;
            }
            if(curr->right!=NULL)
            {
                queue[rear]=curr->right;
                rear++;
            }
            count--;
        }
        depth+=1;
    }
    return wpl;
}
bitree newnode(int weight)
{
    bitree node = (bitree)malloc(sizeof(treenode));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    /* 权值 1,2,3,4 的哈夫曼树：
             10
            /  \
           6    4
          / \
         3   3
        / \
       1   2
    */
    bitree l1 = newnode(1);
    bitree l2 = newnode(2);
    bitree l3 = newnode(3);
    bitree l4 = newnode(4);

    bitree a = newnode(3);        // 内部节点：1、2 的父
    a->left = l1;
    a->right = l2;

    bitree b = newnode(6);        // 内部节点：a、3 的父
    b->left = a;
    b->right = l3;

    bitree root = newnode(10);
    root->left = b;
    root->right = l4;

    printf("WPL = %d\n", wplcaulculate(root));   // 应输出 19

    return 0;
}