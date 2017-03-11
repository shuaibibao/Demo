#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
typedef struct {
	char data[MAXSIZE];
	int top;
}SeqStack,*PSeqStack;
PSeqStack Init_SeqStack()
{
	PSeqStack S;
	S=(PSeqStack)malloc(sizeof(SeqStack));
	if(!S)
	{
		printf("error!\n");
		return NULL;
	}
	S->top=-1;
	return S;
}
int Empty_SeqStack(PSeqStack S)
{
	if(S->top==-1)
		return 1;
	else
		return 0;
}
int Push_SeqStack(PSeqStack S,char x)
{
	if(S->top==MAXSIZE-1)
		return 0;
	else
	{
		S->top++;
		S->data[S->top]=x;
		return 1;
	}
}
int Pop_SeqStack(PSeqStack S,char *x)
{
	if(Empty_SeqStack(S))
	return 0;
	else
	{
		*x=S->data[S->top];
		S->top--;
		return 1;
	}
}
int GetTop_SeqStack(PSeqStack s,char *x)
{
	if(Empty_SeqStack(s))
	   return 0;
	else
	{
		*x=s->data[s->top];
		return 1;
	}
}
void Destroy_SeqStack(PSeqStack *s)
{
	*s=NULL;
	return;
}

typedef double DataType;
typedef struct node{
	DataType data;
	struct node *next;
}StackNode,*PStackNode;
typedef struct {
	PStackNode top;
}LinkStack,*PLinkStack;
PLinkStack Init_LinkStack()
{
	PLinkStack s;
	s=(PLinkStack)malloc(sizeof(LinkStack));
	if(!s)
	{
		printf("error\n");
		return NULL;
	}
	s->top=NULL;
  return s;
}
int Empty_LinkStack(PLinkStack s)
{
	return(s->top==NULL);
}
int Push_LinkStack(PLinkStack s,DataType x)
{
        PStackNode p=NULL;
     p=(PStackNode)malloc(sizeof(StackNode));
	if(!p)
	{
		printf("error\n");
		return 0;
	}
	p->data=x;
	p->next=s->top;
	s->top=p;
	return 1;
}
DataType Pop_LinkStack(PLinkStack s,DataType *x)
{
	PStackNode p;
	*x=s->top->data;
	p=s->top;
	s->top=s->top->next;
	free(p);
	return 1;
}
void Destroy_LinkStack(PLinkStack *s)
{
	PStackNode p,q;
	p=(*s)->top;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	free(*s);
}
int IsNum(char c)
{
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
DataType GetTop_LinkStack(PLinkStack s,DataType *x)
{
	*x=s->top->data;
	return 1;
}
DataType postfix_exp(char A[])
{
	PLinkStack s;
	DataType Result,a,b,c;char ch;
	ch=*A++;
	s=Init_LinkStack();
	while(ch!='#')
	{
		if(IsNum(ch))
			Push_LinkStack(s,ch-'0');
		else
		{
			Pop_LinkStack(s,&b);
			Pop_LinkStack(s,&a);
			switch(ch)
			{
			case '+':c=a+b;break;
			case '-':c=a-b;break;
		    case '*':c=a*b;break;
			case '/':c=a/b;break;
			}
			Push_LinkStack(s,c);
		}
		ch=*A++;
	}
	GetTop_LinkStack(s,&Result);
	Destroy_LinkStack(&s);
	return Result;
}
int priority(char op)
{
     switch(op)
	 {
	 case '#':return 1;
     case ')':return 2;
	 case '+':
	 case '-':return 3;
     case '*':
     case '/':return 4;
	 case '(':return 5;
	 default:return 0;
	 }
}
int infix_exp_value(char infixexp[],char postfixexp[])
{
	PSeqStack s;
	char c,w,topelement;
	s=Init_SeqStack();
	Push_SeqStack(s,'#');
	w=*infixexp;
	int flag=1;
	while(flag)
	{

		if(IsNum(w))
		{
			*postfixexp=w;
			postfixexp++;
			w=*(++infixexp);
		}
		else
		{
			if((GetTop_SeqStack(s,&c),c)=='#'&&w=='#')
			{
				Pop_SeqStack(s,&topelement);
				break;
			}
            if((GetTop_SeqStack(s,&c),c)=='('&&w==')')
			{
				Pop_SeqStack(s,&topelement);
				w=*(++infixexp);
			}
			else
			{
				if((GetTop_SeqStack(s,&c),c)=='('||priority((GetTop_SeqStack(s,&c),c))<priority(w))
				{
                          Push_SeqStack(s,w);
						  w=*(++infixexp);
				}
				else
				{
					Pop_SeqStack(s,&topelement);
					*postfixexp=topelement;
					postfixexp++;
				}
			}

		}
	}
	*(postfixexp)='#';
	*(++postfixexp)='\0';
	Destroy_SeqStack(&s);
	return 1;	
}
void main()
{
	   char infixexp[100],postfixexp[100];
	  printf("Enter the expression with '#' ended\n");
	  gets(infixexp);
	  infix_exp_value(infixexp,postfixexp);
	  puts(postfixexp);
	  DataType result=postfix_exp(postfixexp);
	  printf("result=%.2f\n",result); 
	  /*PLinkStack s=Init_LinkStack();
	  Push_LinkStack(s,10);
	  int c;
	  GetTop_LinkStack(s,&c);
	  printf("%d",c);*/
}
