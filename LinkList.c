#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}LNode,*LinkList;
LinkList Creat_LinkList()
{
	LinkList H;
	H=(LinkList)malloc(sizeof(LNode));
	if(H)
	{
		H->next=NULL;
		printf("OK\n");
	}
	return H;
}
void Destroy_LinkList(LinkList *H)
{
    LinkList p,q;
	p=*H;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
int Length_LinkList(LinkList H)
{
	LinkList p=H;
	int count=-1;
	while(p)
	{
        p=p->next;
		count++;
	}
	return count;
}
LinkList Locate_LinkList_Pos(LinkList H,int i)
{
	LinkList p=H;
	int j=0;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i||!p)
	{
		printf("error");
		return(NULL);
	}
	return p;
}
LinkList Locate_LinkList_Value(LinkList H,int x)
{
	LinkList p=H;
	while(p&&p->data!=x)
	{
		p=p->next;
	}
	if(!p)
       return p;
	return NULL;
}
int Insert_LinkList(LinkList H,int i,int x)
{
	LinkList p,q;
	p=Locate_LinkList_Pos(H,i-1);
	if(!p)
	{
		printf("error\n");
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q)
	{
		printf("error");
		return 0;
	}
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}
int Del_LinkList(LinkList H,int i)
{
	LinkList p,q;
	if(H==NULL||H->next==NULL)
	{
		printf("error");
		return 0;
	}
	p=Locate_LinkList_Pos(H,i-1);
	if(p==NULL||p->next==NULL)
	{
		printf("error");
		return 0;
	}
		q=p->next;
		p->next=q->next;
		free(q);
		return 1;
	}






void main()
{
	LinkList H;
    H=Creat_LinkList();
	printf("%d",Length_LinkList(H));
	Destroy_LinkList(&H);
	printf("%d",Length_LinkList(H));
}

