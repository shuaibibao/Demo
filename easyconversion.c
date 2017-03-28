#include<iostream>  
#include<string>  
using namespace std;   
int main()   
{   
    int n,m;       
    string ans;      
    char num[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};       
    cin>>n>>m;       
    while (n)       
    {           
        ans=num[n%m]+ans;           
        n=n/m;           
        }        
        cout<<ans;         
        return 0;  
}  