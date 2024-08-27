#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&arr , vector<vector<int>>&dp ,int row,int col)
{
	int n=arr.size() , m = arr[0].size();
	if(row >= n || col >= m) return 0;
	if(dp[row][col] != -1)return dp[row][col];
	int right  =   arr[row][col] + solve(arr,dp , row , col+1);
	int bottom =  arr[row][col] + solve(arr , dp , row+1 ,col);

	return dp[row][col] = max(right , bottom);
}

int main()
{
	int n , m;
	cin>>n>>m;

	vector<vector<int>>arr (n , vector<int>(m , 0));
	vector<vector<int>>dp(n , vector<int>(m,-1));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			arr[i][j] = a;
		}
	}
	cout<<solve(arr , dp , 0 , 0);
	return 0;
}
