#include<stdio.h>

int min(int a,int b){

	if(a < b)return a;
	else return b;
}

int max(int a , int b){
	if(a > b)return a;
	return b;
}

int abs(int a){
	if(a < 0)return (-1*a);
	return a;
}
