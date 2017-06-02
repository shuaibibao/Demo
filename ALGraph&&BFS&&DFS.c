//运用邻接表实现图的存储结构
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
#define False 0
#define True 1
int visited[MaxVertexNum];//用来区分节点是否已经被访问过了
//typedef char InfoType;//添加权值属性
typedef char VertexType;
typedef struct node
{
	int adjvertex; //表头向量中的下标
	//InfoType info;
	struct node *next;//指向邻接点的指针域
}EdgeNode;
typedef struct vnode   //顶点节点
{
	VertexType vertex;//顶点域,用来存放定点节点的内容
	EdgeNode *firstedge; //边表头指针
}VertexNode;
typedef struct {
	VertexNode adjlist[MaxVertexNum];//邻接表
	int vertexNum,edgeNum;//顶点数和边数
}ALGraph;
void CreateALGraph(ALGraph *G)
{
	int i,j,k;
	EdgeNode *p;
	scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
	getchar();
	for(i=0;i<G->vertexNum;i++)
	{
		scanf("%c",&(G->adjlist[i].vertex));
		G->adjlist[i].firstedge=NULL;
	}
	getchar();
	for(k=0;k<G->edgeNum;k++)
	{
		scanf("%d,%d",&i,&j);
		p=(EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvertex=j;
		p->next=G->adjlist[i].firstedge;//将新的边表节点p插入到顶点vi的链表头部
		G->adjlist[i].firstedge=p;
		//使得产生无向图 
		p=(EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvertex=i;
		p->next=G->adjlist[j].firstedge;//将新的边表节点p插入到顶点vi的链表头部
		G->adjlist[j].firstedge=p;
		getchar();
	}
}
void ALGprint(ALGraph *g)
{
	ALGraph *temp=g;
	for(int i=0;i<temp->vertexNum;i++)
	{
		printf("%c->",temp->adjlist[i].vertex);
		while(temp->adjlist[i].firstedge)
		{
	     	printf("%d->",temp->adjlist[i].firstedge->adjvertex);
			temp->adjlist[i].firstedge=temp->adjlist[i].firstedge->next;
		}
		printf("null\n");
	}
}
//运用Recur思想实现深度优先搜索
void Visit(ALGraph G,int v)
{
	printf("%c->",G.adjlist[v].vertex);
}
void DFS(ALGraph G,int v)
{
	EdgeNode *p;
	int w;
	Visit(G,v);//访问当前节点的内容
	visited[v]=True;
	for(p=G.adjlist[v].firstedge;p;p=p->next)
	{
		w=p->adjvertex;
		if(!visited[w])
			DFS(G,w);
	}
}
void DFStraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vertexNum;v++)
	    visited[v]=False;//进行初始化操作 
	for(v=0;v<G.vertexNum;v++)
		if(!visited[v])
			DFS(G,v);//对当前的点进行遍历 
}
//-------------------------------------------------------------------
typedef int DataType;
#define MAXSIZE 100
typedef struct{
	DataType data[MAXSIZE];
	int front,rear;
}SeqQueue,*PSeqQueue;
PSeqQueue Init_SeqQueue()
{
	PSeqQueue Q;
	Q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(Q)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}
int Empty_SeqQueue(PSeqQueue Q)
{
	if(Q&&Q->front==Q->rear)
		return 1;
	else
		return 0;
}
int In_SeqQueue(PSeqQueue Q,DataType x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		printf("full of the queue:\n");
		return -1;
	}
	else
	{
		Q->rear=(Q->rear+1)%MAXSIZE;
	    Q->data[Q->rear]=x;
		return 1;
	}
}
int Out_SeqQueue(PSeqQueue Q,DataType *x)
{
    if(Q->front==Q->rear)
	{
		printf("empty\n");
		return -1;
	}
	else
	{
		*x=Q->data[(Q->front+1)%MAXSIZE];
		Q->front=Q->front+1;
			return 1;
	}
}
//运用队列实现图的广度优先搜索 
void BFS(ALGraph G,int v)
{
	EdgeNode *p;
	int u,w;
	PSeqQueue Q;
	Q=Init_SeqQueue();
	Visit(G,v);
	visited[v]=True;
	In_SeqQueue(Q,v);  //把下标v送入队列
	while(!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q,&u);
		for(p=G.adjlist[u].firstedge;p;p=p->next)
		{
			w=p->adjvertex;
			if(!visited[w])
			{
				Visit(G,w);;
				visited[w]=True;
			    In_SeqQueue(Q,w);
			}
		}
	}
}
void BFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vertexNum;v++)
		visited[v]=False;
	for(v=0;v<G.vertexNum;v++)
		if(!visited[v])
			BFS(G,v);
}
int main()
{
	ALGraph G;
	CreateALGraph(&G);
	ALGprint(&G);
	printf("DFS\n");
    DFStraverse(G);
	printf("\nBFS:\n");
	BFSTraverse(G);
	return 0;
}