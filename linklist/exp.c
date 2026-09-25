#include<stdio.h>
#include<stdlib.h>//调用malloc函数
//创建链表结构体 头表data=0 尾表指向NULL
typedef struct node
{
    int data;
    struct node* next;
}Node;
//initialize
Node* initialize()
{
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
//头插法 L为头链表地址 e为要插入的数据
void inserthead(Node*L,int e)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}
//遍历
void printlist(Node*L)
{
    Node*p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
//寻找指向尾表的地址(尾插法前提)
Node* gettail(Node*L)
{
    Node*p=L;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}
//尾插法 
Node* inserttail(Node*tail,int e)
//Node*tail是gettail函数的返回值(指向尾表的地址)
{
    Node*p=(Node*)malloc(sizeof(Node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
    //连续使用时需 tail = inserttail(tail,e);以确保tail的值恒为尾表地址
    //或者每次使用前再gettail一次
}
//在第pos个节点后插入
int insernode(Node*L,int pos,int e)
{
    Node*p=L;//储存插入位置的前驱节点
    int i=0;
    while(i<pos-1)//只需向前pos-1次
    {
        p=p->next;
        i++;
        if (p==NULL)
        {
            return 0;
        }
    }
    //新节点
    Node*q=(Node*)malloc(sizeof(Node));
    q->next=p->next;
    q->data=e;
    p->next=q;
    return 1;
}
//删除节点(默认头节点的pos为0)
int deletenode(Node*L,int pos)
{
    Node*p=L;
    int i=0;
    while(i<pos-1)//寻找删除节点的前驱节点
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
    Node*q=p->next;//找到要删除的节点p
    p->next=q->next;
    free(q);
    return 1;
}
//获取链表长度(包括头节点)
int length(Node*L)
{
    int len=0;
    Node*p=L;
    while (p!=NULL)
    {
        p=p->next;
        len++;   
    }
    return len;
}
//释放链表
void freelist(Node*L)
{
    Node*p=L->next;
    Node*q;

    while (p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}
int main(){
    Node* list=initialize();
    inserthead(list,10);
    inserthead(list,20);
    inserthead(list,30);
    Node*tail=gettail(list);
    tail = inserttail(tail,20);
    tail = inserttail(tail,30);
    insernode(list,6,40);
    deletenode(list,2);
    printlist(list);
    printf("%d\n",length(list));
    freelist(list);
    printf("%d\n",length(list));
    return 0;
}