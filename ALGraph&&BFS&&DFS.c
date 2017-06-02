//�����ڽӱ�ʵ��ͼ�Ĵ洢�ṹ
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 30
#define False 0
#define True 1
int visited[MaxVertexNum];//�������ֽڵ��Ƿ��Ѿ������ʹ���
//typedef char InfoType;//���Ȩֵ����
typedef char VertexType;
typedef struct node
{
	int adjvertex; //��ͷ�����е��±�
	//InfoType info;
	struct node *next;//ָ���ڽӵ��ָ����
}EdgeNode;
typedef struct vnode   //����ڵ�
{
	VertexType vertex;//������,������Ŷ���ڵ������
	EdgeNode *firstedge; //�߱�ͷָ��
}VertexNode;
typedef struct {
	VertexNode adjlist[MaxVertexNum];//�ڽӱ�
	int vertexNum,edgeNum;//�������ͱ���
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
		p->next=G->adjlist[i].firstedge;//���µı߱�ڵ�p���뵽����vi������ͷ��
		G->adjlist[i].firstedge=p;
		//ʹ�ò�������ͼ 
		p=(EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvertex=i;
		p->next=G->adjlist[j].firstedge;//���µı߱�ڵ�p���뵽����vi������ͷ��
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
//����Recur˼��ʵ�������������
void Visit(ALGraph G,int v)
{
	printf("%c->",G.adjlist[v].vertex);
}
void DFS(ALGraph G,int v)
{
	EdgeNode *p;
	int w;
	Visit(G,v);//���ʵ�ǰ�ڵ������
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
	    visited[v]=False;//���г�ʼ������ 
	for(v=0;v<G.vertexNum;v++)
		if(!visited[v])
			DFS(G,v);//�Ե�ǰ�ĵ���б��� 
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
//���ö���ʵ��ͼ�Ĺ���������� 
void BFS(ALGraph G,int v)
{
	EdgeNode *p;
	int u,w;
	PSeqQueue Q;
	Q=Init_SeqQueue();
	Visit(G,v);
	visited[v]=True;
	In_SeqQueue(Q,v);  //���±�v�������
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