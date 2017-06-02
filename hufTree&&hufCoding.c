#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define N 20
typedef int datatype;
typedef struct {
	char ch;
	datatype weight;
	int lchild,rchild,parent;
}HTnode;
typedef struct {
	char  *code;
	char leaf;
	int length;
}CodeType;

void MPhuftree(HTnode huftree[],int n)//n is the leaf's number
{
	int i,j;
	HTnode temp;
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(huftree[j].weight>huftree[j+1].weight)
			{
				temp=huftree[j];
				huftree[j]=huftree[j+1];
				huftree[j+1]=temp;
			}
}

void Select(HTnode huftree[],int n,int *s1,int *s2)//for the sorted huftree
{
	int min1=100;
	int min2=100;
	int i;
	for(i=1;i<=n;i++)
	{
		if(huftree[i].parent!=-1)
			continue;
		if(min1>huftree[i].weight)
		{
			min1=huftree[i].weight;
			*s1=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i==(*s1)||huftree[i].parent!=-1)
			continue;
		else
		{
			if(min2>huftree[i].weight)
			{
			 	min2=huftree[i].weight;
			    *s2=i;
			}
		}
	}
}

void Hufcoding(HTnode huftree[],CodeType cd[],int w[],int n)
{
   int i,k,s1,s2,m,f,c,sum;
   char temp[N];
   m=2*n-1;
   
   for(i=1;i<=n;i++)
   {
	   huftree[i].weight=w[i-1];
	   huftree[i].lchild=huftree[i].rchild=huftree[i].parent=-1;
   }
   for(i=n+1;i<=m;i++)
   {
	   
	   huftree[i].weight=-1;
	   huftree[i].lchild=huftree[i].rchild=huftree[i].parent=-1;
   }
   MPhuftree(huftree,n);
   for(i=1;i<=n-1;i++)
   {
	   
	   Select(huftree,n+i-1,&s1,&s2);
	   sum=huftree[s1].weight+huftree[s2].weight;
	   huftree[n+i].weight=sum;
	   huftree[s1].parent=huftree[s2].parent=n+i;
	   huftree[n+i].lchild=s1;huftree[n+i].rchild=s2;
   }
   for(i=1;i<=n;i++)
   {
	   	 
	   c=0;
	   for(k=i,f=huftree[i].parent;f!=-1;k=f,f=huftree[f].parent)
	   {
		   if(huftree[f].lchild==k)
		   {
			   temp[c]='0';
			   c++;
		   }
		   else
		   {
			   temp[c]='1';
			   c++;
		   }
	   }
	   cd[i].code=(char *)malloc((c+1)*sizeof(char));
	   c--;
	   k=0;
	   while(c>=0)
		   cd[i].code[k++]=temp[c--];
	   cd[i].leaf=huftree[i].ch;
	   cd[i].length=k;
	   cd[i].code[k]='\0';
   }
}
//kmp

int StrLength(char *s)
{
	int i=0;
	while(s[i]!='\0') i++;
	return i;
}
int StrConcat(char *s1,char *s2,char *s)
{
	int i=0,j,len1,len2;
	len1=StrLength(s1);
	len2=StrLength(s2);

	if(len1+len2>MAXSIZE-1)
		return 0;
	j=0;
	while(s1[j]!='\0')
	{
		s[i]=s1[j];
		i++;
		j++;	
	}
	j=0;
    while(s2[j]!='\0')
	{
		s[i]=s2[j];
		i++;
	    j++;
	printf("ok");
	}
	s[i]='\0';
	return 1;
}
int StrSub(char *t,char *s,int i,int len)
{
	int slen;
	slen=StrLength(s);
	if(i<1||i>slen||len<0||len>slen-i+1)
	{
		printf("error\n");
		return 0;
	}
	int j;
	for(j=0;j<len;j++)
	  t[j]=s[i+j-1];
	t[j]='\0';
	return 1;
}
int StrCmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0')
		i++;
	return(s1[i]==s2[i]);
}
/*
int StrIndex_BF(char *s,char *t)
{
      int i=0,j=0;
	  while(i<StrLength(s)&&j<StrLength(t))
	      if(s[i]==t[j])
		  {
			  i++;
			  j++;
		  }
		  else{
			  i=i-j+1;
			  j=0;
		  }
       if(j==StrLength(t))
	   {   printf("ok\n");
	   return (i-StrLength(t));}
	   else
		   return -1;
}
void GetNext(char *s,int next[])//the best aproches is to think like a computer
{
	int i=1,j=0;
	next[0]=0;
	next[1]=0;
	while(i<StrLength(s))
	{
		
		if(s[i]==s[j])
		{ 
			j=next[i]+1;
			i++;
			next[i]=next[i-1]+1;
			
		}
		else
		{
			j=next[j];
			if(j==0)
			{
			   if(s[i]==s[j])
	            {
				    j++;
			        i++;
			        next[i]=1;
				}
			   else
			   {
				   i++;
				   next[i]=0;
			   }
			}
		}
	}
}

int StrIndex_KMP(char *s,char *t,int pos)//pos is the location to start finding the substring 
{
	int i=pos,j=0,next[100];
	GetNext(t,next);
	while(i<StrLength(s)&&j<StrLength(t))
	  if(s[i]==t[j])
	  {
		i++;
		j++;
	  }
      else
	  {
		j=next[j];
		if(j==0)
		   if(s[i]==t[j])
		   {
		      i++;
		      j++;
		   }
		   else
		   {
			   i++;
		   }
	  }
	if(j==StrLength(t))
		return i-StrLength(t);
	else 
		return -1;
}*/
int StrIndex(char *s,char *t)
{
      int i=0;
	  while(i<StrLength(t))
	      if(s[i]==t[i])
		  {
			  i++;
		  }	  
	      else
		    return -1;
      return 0;
}
void JieMi(char *s,CodeType cd[],int n,char *des)
{
    int m=-1,count=0,k;
	int sLen=StrLength(s);
	//printf("%d",sLen);
	while(sLen>0)
		for(int i=1;i<=n;i++)
		{
		     m= StrIndex(s,cd[n-i+1].code);
		   if(m!=-1)
		   {			  
				puts("hello");
			   for(k=0;k<=sLen-StrLength(cd[n-i+1].code)-1;k++)
			   {
				   s[k]=s[k+StrLength(cd[n-i+1].code)];
			   }
			   for(k=0;k<=StrLength(cd[n-i+1].code)-1;k++)
			   {
				   s[sLen-k-1]='#';
			   }
			   	 puts(s);
			   sLen=sLen-StrLength(cd[n-i+1].code);
			   des[count]=cd[n-i+1].leaf;
			     printf("%c\n",des[count]);
			   count++;
			   break;
		   }
		}
	des[count]='\0';
}
int main()
{
   char ch;int i=1,int n;
   int w[20];
   char s;
   char *str=&s;
   HTnode huftree[20];
   CodeType cd[20];
   /*while(1)
   {
	   printf("enter the leaf's value:\n");
	   scanf("%c",&ch);
		  if(ch=='#')
			  break;
	   huftree[i].ch=ch;
	   printf("enter the leaf's weight:\n");
	   scanf("%d",w+i);
	   i++;
	   getchar();//restrain the enter
   }
   n=--i;*/
   huftree[1].ch='a';
   huftree[2].ch='b';
   huftree[3].ch='c';
   huftree[4].ch='d';
   huftree[5].ch='e';
   huftree[6].ch='f';
   huftree[7].ch='g';
   huftree[8].ch='h';
   for(i=0;i<8;i++)
	   w[i]=i+1;
   n=8;
   Hufcoding(huftree,cd,w,n);
   printf("-------------------------\n");
   for(i=1;i<=n;i++)
   {
	 printf("%c->",cd[i].leaf);
     puts(cd[i].code);
	 printf("\n");
   }

   printf("enter the bianry string :\n");
   gets(str);
   char des;
	   JieMi(str,cd,n,&des);
   printf("resloved:\n");
   puts(&des);
}