#include<stdio.h>  
int cont=1;  
void print(int str[],int n);
//build a full arrangement mode
void perm(int str[],int k,int n)  
{  
    int i,temp;  
    if(k==n-1)print(str,n);//k��n-1��ȣ���һ�˵ݹ�����   
    else{  
        for(i=k;i<n;i++){//�ѵ�ǰ�ڵ�Ԫ��������ڵ�Ԫ�ؽ���   
            temp=str[k]; str[k]=str[i]; str[i]=temp;//����   
            perm(str,k+1,n);//����һ���ڵ�Ԫ��������ڵ�Ԫ�ؽ���   
            temp=str[i]; str[i]=str[k]; str[k]=temp;//�ָ�ԭ״    
        }  
    }  
}  
/* �������ж��������� str[] �Ƿ��������ջ����, �����������*/  
//���������е��κ�һ������������б���С����Ӧ���ǵ���� 
void print(int str[],int n)   
{  
    int i,j,k,l,m,flag=1,b[2];   
    for(i=0;i<n;i++)    /* ��ÿ��str[i] �ж�������С�����Ƿ�Ϊ��������*/   
    {  
        m=0;   
        for(j=i+1;j<n&&flag;j++){   
            if (str[i]>str[j])  
            {  
                if (m==0) b[m++]=str[j];//��¼str[i]�����С����   
                else   
                {  
                    //���֮����ֵ����ȼ�¼�������󣬸ı��Ǳ���   
                    if (str[j]>b[0]) flag=0;  
                    //�����¼�����С����   
                    else b[0]=str[j];   
                }   
            }  
        }   
    }   
    if(flag)        /* �����ջ��������� str[] �е�����*/   
    {     
        printf(" %2d:",cont++); //������   
        for(i=0;i<n;i++)   
            printf("%d",str[i]);//�������   
        printf("\n");   
    }   
}   
int main()   
{  
    int str[100],n,i;   
    printf("input a number:\n");     /* ������е�Ԫ�ظ���*/   
    scanf("%d",&n);   
    for(i=0;i<n;i++)         /* ��ʼ�����м���*/   
        str[i]=i+1;             //��i���ڵ㸳ֵΪi+1   
    printf("input the result:\n");   
    perm(str,0,n);              //���õݹ�  
    printf("\n");   
    return 0;   
}   