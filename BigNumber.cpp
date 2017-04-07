#include<iostream>
#include<math.h>
using namespace std;
const double e=2.7182818284590452354,pi=3.141592653589793239;
double str_ling(int n)
{
	return 0.5*log10(2*pi*n)+n*log10(n/e);
}
int main()
{
	int t,m;
	cin>>t;
	while(t--)
	{
		cin>>m;
		cout<<(int)str_ling(m)+1<<endl;
	}
	system("pause");
	return 0;
}
/*运用Stirling公式进行求解，因为求位数，故复杂度是很低的*/