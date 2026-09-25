#include<stdio.h>
#include <stdlib.h>
typedef struct treenode
{
    int data;
    struct treenode* lchild;
    struct treenode* rchild;
}treenode;
typedef treenode* bitree;
//二叉排序数中左孩子比父节点小，右孩子比父节点大

void preorder(bitree T)
{//前序遍历
    if(T==NULL){
        return;
    }
    printf("%d ",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}
int searchbit(bitree T,int value,bitree parent,bitree* pos)
{//第一次的parent值为null
    if (T==NULL)
    {
        *pos=parent;
        return 0;
    }
    if(T->data==value)
    {
        *pos=T;
        return 1;
    }
    if(T->data>value)
    {
        return searchbit(T->lchild,value,T,pos);
    }
    else
    {
        return searchbit(T->rchild,value,T,pos);
    }
}
int insertbit(bitree* T,int value)
{
    bitree parent;
    bitree pos;
    bitree curr;
    int status=searchbit(*T,value,NULL,&pos);
    if(status==0)//未找到该元素 创建新节点
    {
        curr=(bitree)malloc(sizeof(treenode));
        curr->data=value;
        curr->lchild=NULL;
        curr->rchild=NULL;
        if(pos==NULL)//树为空 该元素做根
        {
            *T=curr;
        }
        else if(value<pos->data)
        {
            pos->lchild=curr;
        }
        else
        {
            pos->rchild=curr;
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
int delete(bitree* d)
{
    bitree temp, record;
    if((*d)->rchild==NULL)
    {
        temp =*d;
        *d=(*d)->lchild;
        free(temp);
    }
    else if((*d)->lchild==NULL)
    {
        temp =*d;
        *d=(*d)->lchild;
        free(temp);
    }
    else
    {
        temp=*d;
        record=(*d)->lchild;
        while(record->rchild!=NULL)
        {
            temp=record;
            record=record->rchild;
        }
        (*d)->data=record->data;
        if(temp!= *d)
        {
            temp->rchild=record->lchild;
        }
        else
        {
            temp->lchild=record->lchild;
        }
        free(record);
    }
}
int deletebit(bitree* T,int value)
{
    if(*T==NULL)
    {
        return 0;
    }
    else
    {
        if((*T)->data==value)
        {
            return delete(*T);
        }
        else if((*T)->data>value)
        {
            return deletebit(&(*T)->lchild,value);
        }
        else
        {
            return deletebit(&(*T)->rchild,value);
        }
    }
}
bitree mk(int d)
{
    bitree p = (bitree)malloc(sizeof(treenode));
    p->data = d; p->lchild = p->rchild = NULL;
    return p;
}
int main()
{
    bitree n70=mk(70), n55=mk(55), n80=mk(80), n49=mk(49), n75=mk(75),
           n98=mk(98), n95=mk(95), n30=mk(30), n53=mk(53),n39=mk(39);
    n70->lchild=n55;  n70->rchild=n80;
    n55->lchild=n49;  n49->lchild=n30;
    n30->rchild=n39;  n49->rchild=n53;
    n80->lchild=n75;  n80->rchild=n98;
    n98->lchild=n95;
    bitree pos=NULL;
    searchbit(n70,53,NULL,&pos);
    printf("%d\n",pos->data);
    preorder(n70);
    insertbit(&n70,99);
    printf("\n");
    preorder(n70);
    return 0;
}
