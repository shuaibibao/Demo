#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct {
	int data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;
PSeqStack Init_SeqStack()
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(!S)
	{
		printf("error!\n");
		return NULL;
	}
	S->top=-1;
	return S;
}
int Empty_SeqStack(PSeqStack S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}
int Push_SeqStack(PSeqStack S,int x)
{
	if(S->top==MAXSIZE-1)
		return 0;
	else
	{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}
int Pop_SeqStack(PSeqStack S,int *x)
{
	if(Empty_SeqStack(S))
	return 0;
	else
	{
		*x=S->data[S->top];
		S->top--;
		return 1;
	}
}

void main(){
	PSeqStack s=Init_SeqStack();
}
