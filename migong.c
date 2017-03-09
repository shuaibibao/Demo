#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define M 6
#define N 8
typedef struct{
	int x,y;
}item;
typedef struct{
	int x,y,d;
}DataType;
typedef struct {
	DataType data[MAXSIZE];
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
int Push_SeqStack(PSeqStack S,DataType x)
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
int Pop_SeqStack(PSeqStack S,DataType *x)
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
void Destroy_SeqStack(PSeqStack *s)
{
	if(*s)
		free(*s);
	*s=NULL;
}
int mazepath(int maze[][N+2],item move[],int x0,int y0,int path[][N+2])
{
	PSeqStack s;
	DataType temp;
	int x,y,d,i,j;
	temp.x=x0;temp.y=y0;temp.d=-1;
	s=Init_SeqStack();
	Push_SeqStack(s,temp);
	while(!Empty_SeqStack(s))
	{
		Pop_SeqStack(s,&temp);
		x=temp.x;y=temp.y;d=temp.d+1;
		while(d<4)
		{
          i=x+move[d].x;j=y+move[d].y;
		  if(maze[i][j]==0)
		  {
			  temp.x=x;
			  temp.y=y;
			  temp.d=d;
			  Push_SeqStack(s,temp);
			  x=i;y=j;maze[x][y]=-1;
			  if(x==M&&y==N)
			  {
				  while(!Empty_SeqStack(s))
				  {
					  Pop_SeqStack(s,&temp);
					  path[temp.x][temp.y]=1;
				  }

			  }
			  else
			  {
				  d=0;
			  }
		  
		  }
		  else  
			  d++;
		}
	}
	Destroy_SeqStack(&s);
	return 0;
}
void main()
{
	item move[4];
move[0].x=0;move[0].y=1;
move[1].x=1;move[1].y=0;
move[2].x=0;move[2].y=-1;
move[3].x=-1;move[3].y=1;
    int x0=1,y0=1;
	int maze[M+2][N+2]={1,1,1,1,1,1,1,1,1,1,
		                1,0,1,1,1,0,1,1,1,1,
						1,0,0,0,0,1,1,1,1,1,
						1,0,1,0,0,0,0,0,1,1,
						1,0,1,1,1,0,0,1,1,1,
						1,1,0,0,1,1,0,0,0,1,
						1,0,1,1,0,0,1,1,0,1,
						1,1,1,1,1,1,1,1,1,1};
	int path[M+2][N+2]={0,0,0,0,0,0,0,0,0,0,
	                    0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0};
      mazepath(maze,move,x0,y0,path);
	  for(int i=0;i<M+2;i++)
	  { 
		  for(int j=0;j<N+2;j++)
		    printf("%d ",path[i][j]);
	      printf("\n");
	  }
}
