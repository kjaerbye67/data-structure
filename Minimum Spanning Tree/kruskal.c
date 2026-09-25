#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff //2的31次方-1 用于表示两点间无连线
typedef struct Grph
{
    char vertex[MAXSIZE];      //顶点名数组
    int arc[MAXSIZE][MAXSIZE]; //邻接矩阵
    int vertex_num;            //顶点数
    int edge_num;              //边数
}Grph;
typedef struct Edge
{
    int begin;
    int end;
    int weight;
}Edge;
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
    //每条边的权值
    G->arc[0][1]=10;
    G->arc[0][5]=11;

    G->arc[1][2]=18;
    G->arc[1][6]=16;
    G->arc[1][8]=12;

    G->arc[2][3]=22;
    G->arc[2][8]=8;

    G->arc[3][4]=20;
    G->arc[3][6]=24;
    G->arc[3][7]=16;
    G->arc[3][8]=21;

    G->arc[4][5]=26;
    G->arc[4][7]=7;

    G->arc[5][6]=17;

    G->arc[6][7]=19;
     for(int i=0;i < G->vertex_num;i++)
    {
        for(int j=0;j < G->vertex_num;j++)
        {
            G->arc[j][i]=G->arc[i][j];//对称性
        }
        
    }
}
void swap(Edge* edges,int i,int j)
{     //交换两条边的顺序
    int temp;
    temp=edges[i].begin;
    edges[i].begin=edges[j].begin;
    edges[j].begin=temp;

    temp=edges[i].end;
    edges[i].end=edges[j].end;
    edges[j].end=temp;

    temp=edges[i].weight;
    edges[i].weight=edges[j].weight;
    edges[j].weight=temp;
}
void sortedges(Edge edges[],int edge_num)
{
    for(int i=0;i<edge_num;i++)
    {
          for (int j = i+1; j < edge_num; j++)
          {
            if(edges[i].weight>edges[j].weight)
            {
                swap(edges,i,j);
            }
          }
          
    }
}
int find(int* parent,int index)
{
    while(parent[index]>0)
    {
        index=parent[index];
    }
    return index;
}
void kruskal(Grph G)
{
      Edge edges[MAXEDGE];
      int k = 0;
      for (int i = 0; i < G.vertex_num; i++)
          for (int j = i + 1; j < G.vertex_num; j++)
              if (G.arc[i][j] < MAX)
              {
                  edges[k].begin = i;
                  edges[k].end = j;
                  edges[k].weight = G.arc[i][j];
                  k++;
              }

      sortedges(edges, G.edge_num);

      int parent[MAXSIZE];
       for (int i = 0; i < G.vertex_num; i++)
        parent[i] = 0;

    for (int i = 0; i < G.edge_num; i++)
    {
        int n = find(parent, edges[i].begin);
        int m = find(parent, edges[i].end);
        if (n != m)
        {
            parent[n] = m;
            printf("(%c,%c) %d\n", G.vertex[edges[i].begin],G.vertex[edges[i].end],edges[i].weight);
        }
    }
}
int main()
{
    Grph G;
    creatgraph(&G);
    kruskal(G);
    return 0;
}