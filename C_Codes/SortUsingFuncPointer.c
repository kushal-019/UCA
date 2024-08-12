#include <stdio.h>
#include <stdlib.h>



void swapval(int *arr , int a , int b)
{
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
	return ;
}

int compareAsc(int a, int b)
{
	return a>b;
}
int compareDesc(int a,int b)
{
	return b>a;
}

void printArr(int *arr , int size){
	for(int i=0;i<size;i++)
		printf("%d " , arr[i]);
	printf("\n");
	return ;
}

void sortingAlgo(int *arr , int size  , int (*compare)(int , int))
{
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(compare(arr[i]  , arr[j]))
					{
						swapval(arr , i , j);
					}
		}
	}
	printArr(arr , size);
	return ;
}

int main()
{
	int n;
	scanf("%d" , &n);
	int *arr = (int*)malloc(sizeof(int) * n);

	for(int i=0;i<n;i++)
	{
		scanf("%d" ,&arr[i]);
	}
	sortingAlgo(arr , n ,compareAsc);
        sortingAlgo(arr , n , compareDesc);	


	return 0;

}
