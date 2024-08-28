#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int n1=1,n2=1,n3 , sum =0;
	if(n==1 || n == 2)cout<<0;
	for(int i=2;i<n;i++)
	{
		n3 = n2+n1;
		if(n3%2 ==0)sum += n3;
		n1 = n2;
		n2 = n3;		
	}
	cout<<sum;
	return 0;
}
