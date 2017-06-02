//Create Graphics
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
typedef char VertexType;
typedef int Edgetype;
typedef struct {
	VertexType vertexs[MaxVertexNum];
	Edgetype arcs[MaxVertexNum][MaxVertexNum];
	int vertexNum,edgeNum;
}MGraph;
//adjion matrix
void CreateGraph(MGraph *G)
{
	int i,j,k;
	printf("Enter the graphic's number of vertex and edge:\n");
	scanf("%d%d",&(G->vertexNum),&(G->edgeNum));
	printf("enter the the value of the vertex:\n");
	for(i=0;i<G->vertexNum;i++)
		scanf("%c",&(G->vertexs[i]));//use scanf can not shield the apace and enter
	getchar();//shield the enter
	for(i=0;i<G->vertexNum;i++)
		for(j=0;j<G->vertexNum;j++)
			G->arcs[i][j]=0;
    for(k=0;k<G->edgeNum;k++)
	{
        printf("the row and col of the edge:\n");
		scanf("%d%d",&i,&j);
		G->arcs[i][j]=1;
		G->arcs[j][i]=1;
	}
}
void print_MGraph(MGraph *G)
{
	for(int j=0;j<G->vertexNum;j++)
		printf("%c",G->vertexs[j]);
	printf("\n");
	for(int i=0;i<G->vertexNum;i++)
	{
		for(int j=0;j<G->vertexNum;j++)
			printf("%d  ",G->arcs[i][j]);
		printf("\n");
	}
}
int main()
{
     MGraph G;
	 CreateGraph(&G);
	 print_MGraph(&G);
	 return 0;
}