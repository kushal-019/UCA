#include <stdio.h>

void check(int n)
{
    printf("Printing for %d \n" , n);
    if (n == -n) printf("Zero\n");
    else if(((n >> 31) & 1) == 0) printf("Positive \n");
    else printf("Negative \n");
    
    return;
}


int main()
{
	for(int i=0;i<3;i++)
	{
		int n;
		scanf("%d" , &n);
		check(n);
	}
	return 0;

}
