#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
/*typedef struct 
{
	char data[MAXSIZE];
	int Length;
}SeqString;*/
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
}
void main()//this KMP do not using s[0] store length,this is a big difference,if it had did,there would be more easir
{
	char *s="gdffabcaababcgdfh",*t="abcaababcgd";//if using t as aparameter,easy to error
	int next[100];
    GetNext(t,next);
     for(int i=0;i<StrLength(t);i++)
		 printf("%d  ",next[i]);
	 int index=StrIndex_KMP(s,t,0);
	printf("\n%d\n",index);
}
