#include<bits/stdc++.h>
using namespace std;

int solve(int x,int n)
{
	if(n == 1)return x;
	int val = solve(x , n/2);
	val *= val;
	if(n%2 != 0)val *= x;
	return val;

}

int main()
{
	int x,n,m;
	cin>>x>>n>>m;
	cout<<solve(x,n)/m;
	return 0;
}
