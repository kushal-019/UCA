#include <stdio.h>
#include <stdlib.h>

void merge (int *arr , int start , int mid , int end,int n)
{
    int i = start;
    int j = mid + 1;
    int totalSize = end-start+1;
    int *newArr = (int*)malloc(totalSize * sizeof(int));
    int index = 0;
    while(i<=mid && j<=end)
    {
        if(arr[i] < arr[j])
        {
          newArr[index] = arr[i];
          i++;
        }
        else
        {
          newArr[index] = arr[j];
          j++;
        }
        index++;
    }
    while(i<=mid)
    {
       newArr[index] = arr[i];
      i++;
      index++;
    }
    while(j<=end)
    {
      newArr[index] = arr[j];
      j++;
      index++;
    }
    for(int i=0;i<totalSize;i++)
    {
      arr[start+i] = newArr[i];
    }
    free(newArr);
      return ;
}

void mergeSort(int *arr ,int start , int end ,  int n)
{
	if(start >= end)return ;
	int mid = (end - start)/2 + start;
	mergeSort(arr , start , mid , n);
	mergeSort(arr , mid+1 , end , n);
	merge(arr,start,mid , end , n);
	return ;
}

int main()
{
	int n;
	scanf("%d" , &n);
	int *arr = (int*)malloc(n*sizeof(int));
	//int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d" , &arr[i]);
	}

	mergeSort(arr ,0 , n-1 , n);
	for(int i=0;i<n;i++)
	{
		printf("%d " , arr[i]);
	}
        
        free(arr);
        
	return 0;
}
