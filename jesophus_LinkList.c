#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;
LinkList Create()
{
	 LinkList head,tail,current;
     int length,i;
	 current=(LinkList)malloc(sizeof(Node));
	 if(!current) 
	 {
		 printf("error!\n");
		 return NULL;
	 }
	 head=tail=current;
	 //printf("int data:\n");
	 //scanf("%d",&current->data);
	 printf("enter list's length:\n");
	 scanf("%d",&length);
	 current->data=1;
	 for(i=2;i<=length;i++)
	 {
          current=(LinkList)malloc(sizeof(Node));
		  tail->next=current;
		  tail=current;
		  current->data=i;
	 }
     tail->next=head;
	 return head;
}
void print(LinkList list)
{
	LinkList p=list,s=list;
	printf("%d   ",p->data);
	p=p->next;
	while(p!=s)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}
int josephus_LinkList(LinkList josephus_Link,int s,int m)
{
	LinkList p,pre;
	int count;
	p=josephus_Link;
	for(count=1;count<s;count++)
	  p=p->next;
	printf("print josephus sort:\n");
	while(p!=p->next)
	{
		//pre=p->next;
		//while(pre->next!=p)pre=pre->next;
		for(count=1;count<m;count++)
		{
			pre=p;
	     	p=p->next;
		}
        printf("%d\t",p->data);
		pre->next=p->next;
		free(p);
		p=pre->next;
	}
	printf("%d\t",p->data);
	free(p);
	return 1;
}
void main()
{
     LinkList list;
	list=Create();
	print(list);
	josephus_LinkList(list,1,2);
}
