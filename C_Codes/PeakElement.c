#include<stdio.h>


int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d" ,&arr[i]);
	}
	int start =0 , end = n-1, mid=0;
	while(start < end)
	{
		 mid = (end-start)/2 + start;

		if(arr[mid] < arr[mid+1])
		{
			start = mid+1;
		}
		else
			end = mid;
	}
	printf("%d" , start);
	return 0;
}

