#include<stdio.h>

void * customCalloc(int n){
// initiallising a char array to target every bit 
	char * arr =(char*)malloc( n);
// setting each bit to zero
	for(int i=0;i<m;i++){
	  arr[i] = 0;
        }
// converting ans (void type array) to an array with each bit zero;
        void * ans = (void* )arr;
	return ans;
}

int main(){
	int n ;
	printf("\n enter bits size : \n ");
	scanf("%d" , &n );
// m=passing void array in custom function and converting its each bit to be zero
	void* arr = customCalloc(n );
	
// reconverting void array to char array.
	char* ans = (char*)arr;
	for(int i=0;i<n;i++)printf("%d ",  arr[i]);

	return 0;
}
