#include<bits/stdc++.h>
using namespace std;

void updateEachRow(vector<vector<int>>& arr , int size , int row)
{
	if(row == 0)return ;

	for(int i=0;i<size;i++){
		if(arr[row][i] != 0)arr[row][i] += arr[row-1][i];
	}
	return ;
}

int solveForEachRow(vector<int>&arr , int size)
{
	int maxArea = 0;

	for(int i=0;i<size;i++){
		int area = arr[i];
		int k = i-1;
		while(k >= 0 && arr[k] >= arr[i])area += arr[i], k--;
	       	k = i+1;
		while(k< size && arr[k] >= arr[i]) area += arr[i] , k++;
		maxArea = max(maxArea , area);
	}
	return maxArea;
}

int solve(vector<vector<int>>&arr  , int size)
{
	int ans = 0;
	for(int i=0;i<size;i++){
		updateEachRow(arr , size , i);
		ans = max(ans , solveForEachRow(arr[i] , size));
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;

	vector<vector<int>>arr(n ,vector<int>(n,0));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<solve(arr , n);
	return 0;
}
