#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype;
typedef struct {
	int i,j;
	datatype v;
}triple;
typedef struct {
	triple data[MAXSIZE];
	int m,n,t;
}tripletable;
tripletable transmatrix(tripletable a)
{
	tripletable b;
	int p,q,col;
	b.m=a.n;
	b.n=a.m;
	b.t=a.t;
	if(b.t)
	{
		q=0;
		for(col=1;col<=a.n;col++)
		 for(p=0;p<a.t;p++)
			 if(a.data[p].j==col)
			 {
				 b.data[q].i=col;
				 b.data[q].j=a.data[p].i;
				 b.data[q].v=a.data[p].v;
				 q++;
			 }
	}
    return b;
}
tripletable init()
{
	tripletable a;
	printf("enter the rows ,cols and counts of elemnt not equaled to zero\n");
	scanf("%d%d%d",&a.m,&a.n,&a.t);
	for(int k=0;k<a.t;k++)
	{
		printf("enter the tripletable elements:\n");
			scanf("%d%d%d",&a.data[k].i,&a.data[k].j,&a.data[k].v);
	}
	return a;
}
void print(tripletable a)
{
	int k=0;
	for(int i=1;i<=a.m;i++)
	{
		for(int j=1;j<=a.n;j++)
		{
			if(i==a.data[k].i&&j==a.data[k].j)
			{
				printf("%d  ",a.data[k].v);
				k++;
			}
			else
			{
				printf("0  ");
			}
		}
		printf("\n");
	}
}
tripletable fasttransmatrix(tripletable a)
{
    tripletable b;
	int p,q,col,k;
	//int num[a.n+1],pot[a.n+1];
	int *num,*pot;
	num=(int *)malloc(sizeof(int)*(a.n+1));
    pot=(int *)malloc(sizeof(int)*(a.n+1));
	b.m=a.n;b.n=a.m;b.t=a.t;
	if(b.t)
	{
	  for(col=1;col<a.n;col++)
		  num[col]=0;
	  for(k=0;k<a.t;k++)
		 num[a.data[k].j]++;
	  pot[1]=0;
	  for(col=2;col<=a.n;col++)
		  pot[col]=pot[col-1]+num[col-1];//every col's first element postion
	  for(p=0;p<a.t;p++)
	  {
		  col=a.data[p].j;
		  q=pot[col];
		  b.data[q].i=a.data[p].j;
		  b.data[q].j=a.data[p].i;
		  b.data[q].v=a.data[p].v;
		  pot[col]++;
	  }
	}
	return b;
}

void main()
{
	tripletable a;
	a.m=2;a.n=2;
	a=init();
	print(a);
	printf("the triple sort:\n");
	for(int i=0;i<a.t;i++)
		printf("%d %d %d\n",a.data[i].i,a.data[i].j,a.data[i].v);
	a=transmatrix(a);
	printf("tansmatrix:\n");
	print(a);
	printf("the triple sort:\n");
	for(i=0;i<a.t;i++)
		printf("%d %d %d\n",a.data[i].i,a.data[i].j,a.data[i].v);
	printf("\nfasttansmatrix:\n");
	a=fasttransmatrix(a);
	print(a);
	printf("the triple sort:\n");
	for(i=0;i<a.t;i++)
		printf("%d %d %d\n",a.data[i].i,a.data[i].j,a.data[i].v);

}

	