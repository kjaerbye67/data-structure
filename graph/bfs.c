#include<stdio.h>
#define MAXSIZE 100

typedef struct Grph
{
    char vertex[MAXSIZE];      //顶点名数组
    int arc[MAXSIZE][MAXSIZE]; //邻接矩阵
    int vertex_num;            //顶点数
    int edge_num;              //边数
}Grph;

void creatgraph(Grph* G)
{
    G->vertex_num=9;
    G->edge_num=15;
    G->vertex[0]='A';
    G->vertex[1]='B';
    G->vertex[2]='C';
    G->vertex[3]='D';
    G->vertex[4]='E';
    G->vertex[5]='F';
    G->vertex[6]='G';
    G->vertex[7]='H';
    G->vertex[8]='I';
    for(int i=0;i < G->vertex_num;i++)
    {
        for(int j=0;j < G->vertex_num;j++)
        {
            G->arc[i][j]=0;
        }
    }
    //有边为1
    G->arc[0][1]=1;
    G->arc[0][5]=1;

    G->arc[1][2]=1;
    G->arc[1][6]=1;
    G->arc[1][8]=1;

    G->arc[2][3]=1;
    G->arc[2][8]=1;

    G->arc[3][4]=1;
    G->arc[3][6]=1;
    G->arc[3][7]=1;
    G->arc[3][8]=1;

    G->arc[4][5]=1;
    G->arc[4][7]=1;

    G->arc[5][6]=1;

    G->arc[6][7]=1;
    for(int i=0;i < G->vertex_num;i++)
    {
        for(int j=0;j < G->vertex_num;j++)
        {
            G->arc[j][i]=G->arc[i][j];//对称性
        }
    }
}
int visited[MAXSIZE];//记录已经遍历过的顶点
int front=0;
int rear=0;
int queue[MAXSIZE];//队列

void bfs(Grph G)
{
    int i=0;
    visited[i]=1;
    printf("%c\n",G.vertex[i]);
    queue[rear]=i;
    rear++;
    while (front!=rear)
    {
        i=queue[front];//出队
        front++;
        for (int j = 0; j < G.vertex_num; j++)
        {
            if(G.arc[i][j]==1 && visited[j]==0)
            {
                visited[j]=1;
                printf("%c\n",G.vertex[j]);
                queue[rear]=j;  //入队
                rear++;
            }
        }
    }
}
int main()
{
    Grph G;
    creatgraph(&G);
     for (int i = 0; i < G.vertex_num; i++)
    {
        visited[i]=0;
    }
    bfs(G);
    return 0;
}