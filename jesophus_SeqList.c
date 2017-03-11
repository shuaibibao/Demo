//顺序表的相关算法
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
//顺序表的定义
typedef struct
{
	int data[MaxSize];
	int length;
}SeqList,*PSeqList;

//顺序表的创建
PSeqList Create_SeqList()
{
     PSeqList PL=(PSeqList)malloc(sizeof(SeqList));
	 if(!PL)
	 {
		 printf("false\n");
		 return NULL;
	 }
     printf("输入初始化数据\n");
	 int i=0;PL->length=0;
	 scanf("%d",&PL->data[i]);
	 while(PL->data[i]!=0)
	 {
		   i++;
		 scanf("%d",&PL->data[i]);
           PL->length++;
	 }
	 return PL;
}
void print(PSeqList p)
{
	for(int i=0;i<p->length;i++)
	{
		printf("%d   ",p->data[i]);
	}
}
int Insert(PSeqList p,int pos,int value)
{
     if(!p)
	 {
		 printf("不存在");
		 return 0;
	 }
	 for(int i=p->length-1;i>=pos-1;i--)
		 p->data[i+1]=p->data[i];
     p->data[pos-1]=value;
	 p->length++;
	 return 1;
} 
int del(PSeqList p,int pos)
{
	for(int i=pos-1;i<p->length-1;i++)
	{
		p->data[i]=p->data[i+1];
	}
	p->length--;
	return 1;
}
void jesefus(PSeqList p,int start,int length)
{
	int m=p->length;
    for(int i=0;i<m;i++)
	{   
		int h=(start+length-1)%p->length;
		if(h==0)
		{
			h=p->length;
		}
		printf("%d",p->data[h-1]);
		start=h;
		del(p,start);
		printf("\n");
	
	}
}
void main()
{
	PSeqList PL=Create_SeqList();
	jesefus(PL,1,3);
}
