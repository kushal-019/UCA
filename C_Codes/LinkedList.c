#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node*  next;
	int data;
};
struct Node* createLL(int data , struct Node* head)
{
	if(head == NULL)
	{	
		head = (struct Node*)malloc(sizeof(struct Node));
		head->data = data;
		return head;
	} 
	struct Node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	struct Node* newNext = (struct Node*)malloc(sizeof(struct Node));
	newNext->data = data;
	temp->next = newNext;
	return head;
}

int main()
{
	struct Node* head =NULL;
	int n;
	scanf("%d" , &n);

	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d" , &x);
		head = createLL(x , head);
	}
	printf("reached here");
	while(head)
	{
		printf("%d " ,head->data );
		head = head->next;
	}

	return 0;
}
