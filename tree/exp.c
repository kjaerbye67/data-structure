#include<stdio.h>
typedef struct treenode
{
    char data;
    treenode* lchild;
    treenode* rchild;
}treenode;
typedef treenode* bitree;
//前序遍历
void preorder(bitree T)
{
    if(T==NULL){
        return;
    }
    printf("%c",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}
//已知元素造树
char str[]="ABDH#K###E##CFI###G#J##";
int idx=0;
void createtree(bitree* T)//必须用双重指针,因为修改了穿入参数本身(1,2)
{
    char ch;
    ch=str[idx++];
    if(ch=="#")
    {
        *T=NULL;//1
    }
    else
    {
        *T=(bitree)malloc(sizeof(treenode));//2
        (*T)->data=ch;
        createtree(&(*T)->lchild);
        createtree(&(*T)->rchild);
    }
}
//中序遍历
void inorder(bitree T)
{
    if(T=NULL)
    {
        return;
    }
    inorder(T->lchild);
    printf("%c",T->data);
    inorder(T->rchild);
}
//后续遍历
void postorder(bitree T)
{
    if(T=NULL)
    {
        return;
    }
    posorder(T->lchild);
    posorder(T->rchild);
    printf("%c",T->data);
}
