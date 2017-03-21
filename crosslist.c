#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Datatype;
typedef struct node {
	int row,col;
	struct node *down,*right;
	union{
		struct node *next;
		Datatype value;
	};
}crosslist;
crosslist *creatclinkmat()
{
	int m,n,t,k,i,j,v,s;
	crosslist *p,*q,*head,*cp[MAXSIZE];
	printf("enter the array's cols ,rows and the count of element not equals to zero:\n");
    scanf("%d%d%d",&m,&n,&t);
	s=m>n?m:n;
	p=(crosslist *)malloc(sizeof(crosslist));
	p->row=m;
	p->col=n;
	head=p;
	cp[0]=p;
	for(i=1;i<=s;i++)
	{
			p=(crosslist *)malloc(sizeof(crosslist));
			p->row=0;
			p->col=0;
			cp[i]=p;
			p->right=p;//build circle
			p->down=p;//build circle
			cp[i-1]->next=p;
	}
	cp[s]->next=head;
	for(k=0;k<t;k++)
	{
		printf("enter the triple union:\n");
		scanf("%d%d%d",&i,&j,&v);
		p=(crosslist *)malloc(sizeof(crosslist));
		p->row=i;
		p->col=j;
		p->value=v;
		q=cp[i];
		while(q->right!=cp[i]&&q->right->col<j)//repeat the full row
			q=q->right;
		p->right=q->right;q->right=p;
		q=cp[j];
		while(q->down!=cp[j]&&q->down->row<i)//repeat the full col
			q=q->down;
		p->down=q->down;q->down=p;
	}
	return head;
}
void print(crosslist *head)
{
     crosslist *p=head;
	 int i,j,cols,rows;
	 cols=p->col;
	 rows=p->row;
	 p=p->next->right;
	    for(i=1;i<=rows;i++)
		 {
               for(j=1;j<=cols;j++)
			   {
                   if(i==p->row&&j==p->col)
				   {
                     printf("%d  ",p->value);
					 p=p->right;
				   }
				   else
				   {
				     printf("0  ");
				   }
			   }
			   printf("\n");
			   p=p->next->right;
		 }	 
}
void main()
{
	crosslist *p;
	p=creatclinkmat();
	print(p);
}
