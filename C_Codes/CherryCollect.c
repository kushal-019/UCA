#include<stdio.h>
#include<stdlib.h>
int n , m;

int max(int a, int b) {
    return (a > b) ? a : b;
}


int  solve(char** arr , int** dp , int** visited , int row , int col , int count)
{
	if(row >= n || col >= m || row <0 || col <0 || visited[row][col] == 1)return 0;
	if(dp[row][col] != -1)return dp[row][col];
        if(row == n-1 && col == m-1){
          if(arr[row][col] == '1' ) return 1;
          return 0;
        }
	visited[row][col] = 1;
	int top = 0 , bottom = 0 , left = 0 , right= 0;

		if(arr[row][col] == '1') bottom = max (1 +  solve(arr,dp ,visited , row+1 , col , count) , bottom);
		else if(arr[row][col] == '0') bottom = max (solve(arr,dp ,visited , row+1 , col , count) , bottom);
        	
        	if(arr[row][col] == '1') top = max (1 +  solve(arr,dp ,visited , row-1 , col , count) , top);
		else if(arr[row][col] == '0') top = max (solve(arr,dp ,visited , row-1 , col , count) , top);
		
		if(arr[row][col] == '1') right = max (1 +  solve(arr,dp ,visited , row , col+1 , count) , right);
		else if(arr[row][col] == '0') right = max (solve(arr,dp ,visited , row , col+1 , count) , right);

		if(arr[row][col] == '1') left = max (1 +  solve(arr,dp ,visited , row , col-1 , count) , left);
		else if(arr[row][col] == '0') left = max (solve(arr,dp ,visited , row , col-1 , count) , left);
	
	return dp[row][col]  = max(top , max(bottom , max(left , right)));
	
	
}

int main()
{
	scanf("%d %d" , &n , &m); 
	
        char** arr = (char**)malloc(n * sizeof(char*));
        int** dp = (int**)malloc(n * sizeof(int*));
        int** visited = (int**)malloc(n * sizeof(int*));

        for (int i = 0; i < n; i++) {
            arr[i] = (char*)malloc(m * sizeof(char));
            dp[i] = (int*)malloc(m * sizeof(int));
            visited[i] = (int*)malloc(m * sizeof(int));
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                scanf(" %c", &ch); 
                arr[i][j] = ch;
            }
        }
        if(arr[n-1][m-1] == 'x')return 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j] = -1;
			visited[i][j] = 0;
		}
	}
	printf("%d" , solve(arr , dp,visited , 0 , 0 , 0));
	return 0;
}
