//二叉树的相关算法
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct bnode{
	datatype data;
	struct bnode *lchild,*rchild;
}Bnode,*BTree;
typedef struct node
{
     BTree data;
	 struct node *next;
}StackNode,*PStackNode;
typedef struct
{
	PStackNode top;
}LinkStack,*PLinkStack;
void Visit(datatype ch)
{
	if(ch!='#')
	printf("%c ",ch);
}
PLinkStack Init_LinkStack()
{
	PLinkStack s;
	s=(PLinkStack)malloc(sizeof(LinkStack));
	if(!s)
	{
		printf("error!\n");
		return NULL;
	}
	s->top=NULL;
}
int Empty_LinkStack(PLinkStack s)
{
	return (s->top==NULL);
}
int Push_LinkStack(PLinkStack s,BTree x)
{
	PStackNode p;
	p=(PStackNode)malloc(sizeof(StackNode));
	if(!p)
	{
		printf("error!\n");
		return 0;
	}
	p->data=x;
	p->next=s->top;
	s->top=p;//understand the structure with picture;
}
int Pop_LinkStack(PLinkStack s,BTree *x)
{
    PStackNode p;
	if(Empty_LinkStack(s))
	   {
		printf("error!\n");
		return 0;
	}
	*x=s->top->data;
	p=s->top;
	s->top=s->top->next;
	free(p);
	return 1;
}
/*void Destroy_LinkStack(PLinkStack *s)//s外层结构的改变能传出来
{
	PStackNode p,q;
	if(*s)
	{
		p=(*s)->top;
		while(p)
		{
			q=p;
			p=p->next;
			free(q);
		}
		free(*s);
		*s=NULL;
	}
}*/
BTree CreateBTree()
{
	BTree t;
	char ch;
	ch=getchar();
	if(ch=='#')  t=NULL;
	else
	{
	  t=(BTree)malloc(sizeof(Bnode));
	  t->data=ch;
	  t->lchild=CreateBTree();
	  t->rchild=CreateBTree();
	}
	return t;
}
//非递归的前序遍历算法
void PreOrder(BTree t)
{
    PLinkStack s;
	BTree p=t;
	s=Init_LinkStack();
	while(p||!Empty_LinkStack(s))
	{
		if(p)
		{
			Visit(p->data);
			Push_LinkStack(s,p);
			p=p->lchild;
		}
		else
		{
			Pop_LinkStack(s,&p);
			p=p->rchild;
		}
	}
}
//非递归的后续遍历算法,但是有额外的内存空间
void PostOrder(BTree t)
{
	PLinkStack s1;
	PLinkStack s2;
	BTree p;
	p=t;
	s1=Init_LinkStack();
	s2=Init_LinkStack();
	while(p||!Empty_LinkStack(s2))
	{
		if(p)
		{
			Push_LinkStack(s1,p);
			Push_LinkStack(s2,p);
			p=p->rchild;
		}
		else
		{
			Pop_LinkStack(s2,&p);
			p=p->lchild;
		}
	}
	while(!Empty_LinkStack(s1))
	{
		Pop_LinkStack(s1,&p);
		Visit(p->data);
	}
}
typedef struct
{
	Bnode *node;
	int flag;
}DataType;
/*
void UpdatePreOrder(BTree t)
{
	PLinkStack s;
	DataType sq;
	BTree p=t;
    s=Init_LinkStack();
	while(p||!Empty_LinkStack(s))
	{
		if(p)
		{
			sq.flag=0;
			sq.node=p;
			Push_LinkStack(s,sq)
			p=p->lchild;
		}
		else
		{
			Pop_LinkStack(s,&sq);
			p=sq.node;
			if(sq.flag=0)
			{
				Sq.flag=1;
				Push_SeqStack(s,sq);
				p=p->rchild;
			}
			else
			{
				Visit(p->data);
				p=NULL;
			}
		}
	}
}*/
void InOrder(BTree t)
{
	if(t)
	{
       InOrder(t->lchild);
	   Visit(t->data);
	   InOrder(t->rchild);
	}
}
main()
{
	printf("enter the string to create a Btree:\n");
	BTree t=CreateBTree();
	printf("PreOder res:\n");
	PreOrder(t);
	printf("PostOrder res:\n");
	PostOrder(t);
	printf("InOrder res:\n");
	InOrder(t);
}