#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff //2的31次方-1 用于表示两点间无连线
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
void prim(Grph* G)
{
    int i,j,k;
    int min;
    int weight[MAXSIZE];//候选边
    int index[MAXSIZE]; //值表示出发点，下标表示到达点

    weight[0]=0;
    index[0]=0;
    for(i=1;i<G->vertex_num;i++)//初始化weight和index
    {
        weight[i]=G->arc[0][i];
        index[i]=0;
    }
    for (int i = 1; i < G->vertex_num; i++)
    {
        min=MAX;
        j=0;
        k=0;
        while (j<G->vertex_num)
        {
            if(weight[j]!=0 && weight[j]<min)
            {
                min=weight[j];
                k=j; //k储存最小权值对应元素的下标
            }
            j++;
        }
        printf("%c,%c\n",G->vertex[index[k]],G->vertex[k]);
        weight[k]=0; //表示该点已连接 防止回路

        for (j = 0; j < G->vertex_num; j++)
        {
            //与新开辟的节点的边比较
            if(weight[j]!=0 && G->arc[k][j]<weight[j])
            {
                weight[j]=G->arc[k][j];
                index[j]=k;
            }
        }
    }
}
int main()
{
    Grph G;
    creatgraph(&G);
    prim(&G);
    return 0;
}