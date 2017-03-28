#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAXSIZE 10
#define MAXNODES 50
typedef char datatype;
typedef struct bnode{
	datatype data;
	struct bnode *lchild,*rchild;
}Bnode,*Btree;
//using recursion create Btree
Btree CreateBtree()
{
	Btree t;
	char ch;
	ch=getchar();
	if(ch=='#') t=NULL;
	else
	{
		t=(Bnode *)malloc(sizeof(Bnode));
		t->data=ch;
		t->lchild=CreateBtree();
		t->rchild=CreateBtree();
	}
	return t;
}
Btree CopyTree (Btree t)
{
	Btree p,q,s;
	if(t==NULL)  return NULL;
	p=CopyTree(t->lchild);
	p=CopyTree(t->rchild);
	s=(Bnode *)malloc(sizeof(Bnode));
	s->data=t->data;
	s->lchild=p;
	s->rchild=q;
	return s;
}
void gotoxy(int x,int y)    //设置光标的位置
{ 
      COORD c; 
      c.X=x-1; 
      c.Y=y-1; 
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c); 
}   
void Levcount(Btree t,int L,int num[])
{
	if(t)
	{
		num[L]++;
		Levcount(t->lchild,L+1,num);
		Levcount(t->rchild,L+1,num);
	}
}

void Visit(Btree t,char value[],int bnodes)
{
	if(t)
	{
		printf("%c  ",t->data);
		value[bnodes]=t->data;
	}
}
void RecursionPreOrder(Btree t,char value[],int *bnodes)
{
	if(t)
	{
		(*bnodes)++;//using "()",else error
		Visit(t,value,*bnodes);
		RecursionPreOrder(t->lchild,value,bnodes);
		RecursionPreOrder(t->rchild,value,bnodes);
	}
	else
	{
		(*bnodes)++;
		value[*bnodes]='#';
	}

}
/*void print(Btree t)
{
    int k=1,bnodes=0,j;
	int num[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
		num[i]=0;//innitial num,else error
	char value[MAXNODES];
	for(k=1;k<MAXNODES;k++)
		value[k]=' ';
	RecursionPreOrder(t,value,&bnodes);
		Levcount(t,1,num);
	printf("\n");
	k=1;
	while(num[k])
	{
		k++;
	}
	int lev=k;
    for(k=1;k<=lev;k++)
	{
		for(j=1;j<lev-k+1;j++)
			printf(" ");
		printf("%c ",value[k]); 
		printf("\n");
	}	
}*/
/*void print(Btree t)
{
    int k=1,bnodes=0,j,int x,y;
	char value[MAXNODES];
	for(k=1;k<MAXNODES;k++)
		value[k]=' ';
	RecursionPreOrder(t,value,&bnodes);
	printf("\n");
	for(k=1;k<=bnodes;k++)
	{
		gotoxy(x,y);
		printf("%c",value[1]);
	}
    gotoxy(1,100);
	printf("end");
}*/
void main()
{
	int num[MAXSIZE],k,bnodes=0;
	char value[MAXNODES];
	for(k=1;k<MAXNODES;k++)
		value[k]=' ';
	k=1;
	for(int i=0;i<MAXSIZE;i++)
		num[i]=0;//innitial num,else error
	Btree t,r;
	t=CreateBtree();
	RecursionPreOrder(t,value,&bnodes);
	bnodes=0;
	printf("copy:\n");
    r=CopyTree(t);
	RecursionPreOrder(t,value,&bnodes);
	Levcount(t,1,num);
	printf("count:\n");
	while(num[k])
	{
		printf("%2dlev's counts is %d:\n",k,num[k]);
		k++;
	}
	k=1;
     while(value[k]!=' ')
	{
		printf("%2d's element is %c:\n",k,value[k]);
		k++;
	}
}