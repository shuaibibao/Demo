#include<stdio.h>
int Train_into_Platform(int i,int j)
{
	if(i==0)return 1;
	else if(j==0) return Train_into_Platform(i-1,1);
	else return Train_into_Platform(i-1,j+1)+Train_into_Platform(i,j-1);
}
void main()
{
	int result=Train_into_Platform(4,0);
	printf("%d\n",result);
	 result=Train_into_Platform(5,0);
    printf("%d\n",result);

}
