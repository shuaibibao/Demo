#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
     int data;
	 struct node *next;
}StackNode,*PStackNode;
typedef struct
{
	PStackNode top;
}LinkStack,*PLinkStack;
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
int Empty_LinkStacck(PLinkStack s)
{
	return (s->top==NULL);
}
int Push_LinkStack(PLinkStack s,int x)
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
int Pop_LinkStack(PLinkStack s,int *x)
{
    PStackNode p;
	if(Empty_LinkStacck(s))
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
void Destroy_LinkStack(PLinkStack *s)//s外层结构的改变能传出来
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
}
void Conversion(int num,int jinzhi)
{
	PLinkStack s=Init_LinkStack();
	int temp;
	printf("souce number:\n%d\n",num);
   while(num)
   {

	  temp=num%jinzhi;
	  Push_LinkStack(s,temp);
	  num=num/jinzhi;	  
   }
   printf("after conversion:\n");
   while(!Empty_LinkStacck(s))
   {
	    Pop_LinkStack(s,&temp);
		if(temp>=10)
		   printf("%c",temp-10+'A');
		else 
			printf("%d",temp);
   }
   Destroy_LinkStack(&s);
}
void main()
{
	Conversion(109,16);
	printf("\n");
}
