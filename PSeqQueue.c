#include<stdio.h>
#include<stdlib.h>
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
int Front_SeqQueue(PSeqQueue Q,DataType *x)
{
	if(Q->front==Q->rear)
	{
		printf("empty\n");
		return -1;
	}
	else
	{
		*x=Q->data[(Q->front+1)%MAXSIZE];
			return 1;
	}
}
void Destroy_SeqQueue(PSeqQueue *Q)
{
	if(*Q)
		free(*Q);
	*Q=NULL;
}
void print(PSeqQueue Q)
{
	for(int i=Q->front+1;i<=Q->rear;i++)
	{
		printf("%d ",Q->data[i]);
	}
}
void main()
{
   PSeqQueue Q=Init_SeqQueue();
   In_SeqQueue(Q,1);
   print(Q);
   printf("\n");
   int x;
   Out_SeqQueue(Q,&x);
   printf("%d",x);
}