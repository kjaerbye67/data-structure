#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff //2的31次方-1 用于表示两点间无连线
typedef struct Grph
{
    int vertex[MAXSIZE];      //顶点名数组
    int arc[MAXSIZE][MAXSIZE]; //邻接矩阵
    int vertex_num;            //顶点数
    int edge_num;              //边数
}Grph;
void creategraph(Grph* G)
{
    G->vertex_num=9;
    G->edge_num=16;
    for(int i=0;i<G->vertex_num;i++)
    {
        G->vertex[i]=i;
    }
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = 0; j < G->vertex_num; j++)
        {
            if(i==j)
            {
                G->arc[i][j]=0;
            }
            else
            {
                G->arc[i][j]=MAX;            
            }
        }
        
    }
    G->arc[0][1]=1;
    G->arc[0][2]=5;
    G->arc[1][2]=3;
    G->arc[1][3]=7;
    G->arc[1][4]=5;
    G->arc[2][4]=1;
    G->arc[2][5]=7;
    G->arc[3][4]=2;
    G->arc[3][6]=3;
    G->arc[4][5]=3;
    G->arc[4][6]=6;
    G->arc[4][7]=9;
    G->arc[5][7]=5;
    G->arc[6][7]=2;
    G->arc[6][8]=7;
    G->arc[7][8]=4;
    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j = i+1; j < G->vertex_num; j++)
        {
            G->arc[j][i]=G->arc[i][j];
        }
    }
}
int choose(int distance[],int found[],int vertex_num)
{//返回下次要观察的顶点
    int min=MAX;
    int minpos=-1;
    for (int i = 0; i < vertex_num; i++)
    {
        if(distance[i]<min&&found[i]==0)
        {
            min=distance[i];
            minpos=i;
        }
    }
    return minpos;
}
void dijkstra(Grph G,int begin)
{
    int found[MAXSIZE];   //记录观察过的顶点
    int path[MAXSIZE];
    int distance[MAXSIZE];
    for (int i = 0; i < G.vertex_num; i++)
    {
        found[i]=0;
        path[i]=-1;
        distance[i]=G.arc[begin][i];
    }
    found[begin]=1;
    distance[begin]=0;
    int next;
    for (int i = 1; i < G.vertex_num; i++)
    {
        next=choose(distance,found,G.vertex_num);
        found[next]=1;
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (found[j]==0&&G.arc[next][j]<MAX)
            {
                if(distance[next]+G.arc[next][j]<distance[j])
                {
                    distance[j]=distance[next]+G.arc[next][j];
                    path[j]=next; 
                }
            }
        }
    }
    for(int i=1;i<G.vertex_num;i++)
    {
        printf("V0->V%d:%d\n",i,distance[i]);
        int j=i;
        printf("V%d<-",i);
        while (path[j]!=-1)
        {
            printf("V%d<-",path[j]);
            j=path[j];
        }
        printf("V0\n");
    }
}
int main()
{
    Grph G;
    creategraph(&G);
    int begin =0;
    dijkstra(G,begin);
    return 0;
}