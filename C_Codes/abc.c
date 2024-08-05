#include<stdio.h>

void sort(int *arr , int n)
{
	int flag = 0;
	for(int i = 0 ; i<n;i++)
	{
		for(int j=i+1;j< n;j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

void binarySearch(int *arr , int toSearch , int n)
{
	int left = 0, right = n-1;
	
	while(left <= right)
	{
		int mid = (right -left)/2  +left;
		if(arr[mid] == toSearch)
		{
			printf("Index is : %d \n", mid);	
			return;
		}
		if(arr[mid] > toSearch)right = mid-1;
		else left = mid+1;
	}
	printf("No such element exists \n");
	return ;
}

int main()
{
	int n;
	scanf("%d" , &n);

	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

        printf("input taken \n");
    
	sort(arr ,n);
	
        printf("sorted \n");
        
        for(int i=0;i<n;i++)
        {
            printf("%d " , arr[i]);
        }
        
        printf("\n Enter number to search : ");
	int toSearch;
        
        for(int i=0;i<n;i++)
        {        
	    scanf("%d",&toSearch);
	    binarySearch(arr , toSearch ,n);
        }
	
	return 0;
}
