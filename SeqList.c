#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct List{
	int data[MAXSIZE];
    int length;
}SeqList,*PSeqList;
PSeqList Init_SeqList(int Length){
	PSeqList PL;
	PL=(PSeqList)malloc(sizeof(SeqList));
	if(!PL)
	{
		printf("build error!\n");
		return NULL;
	}
	printf("build success!\n");
	PL->length=Length;
	printf("please input %d number for initial...",Length);
	for(int i=0;i<Length;i++)
	   scanf("%d",&PL->data[i]);
	return PL;
}
int Length_SeqList(PSeqList PL)
{
	return(PL->length);
}
int Location_SeqList(PSeqList PL,int x)
{
	int i=0;
	while(PL->data[i]!=x)
		i++;
	if(i>=PL->length)
	{
        printf("no found!");
		return 0;
	}
	printf("founded!");
	return i+1;
}
int Insert_SeqList(PSeqList PL,int i,int x)
{
    int j;
	if(PL->length>=MAXSIZE)
	{
		printf("outfiting");
		return -1;
	}
	if(i<1||i>PL->length)//
	{
		printf("inputing error");
		return 0;
	}
	for(j=PL->length-1;j>=i-1;j--)
	{
		PL->data[j+1]=PL->data[j];
	}
	PL->data[i-1]=x;
	PL->length++;
	return 1;
}
int Delete_SeqList(PSeqList PL,int i)
{
	int j;
	if(i<1||i>=PL->length)
	{
		printf("inputing error");
		return 0;
	}
	for(j=i-1;j<PL->length;j++)
		PL->data[j]=PL->data[j+1];
	PL->length--;
	return 1;
}
void josephus_SeqList(PSeqList PL,int s,int m)
{
    int s1,i,w;
	s1=s-1;
	printf("outputing....");
	for(i=PL->length;i>0;i--)//
	{
		s1=(s1+m-1)%i;
		w=PL->data[s1];
		printf("%d\n",w);
		Delete_SeqList(PL,s1+1);
	}
}
void main()
{
	PSeqList PL=Init_SeqList(10);
    josephus_SeqList(PL,1,2);
}
