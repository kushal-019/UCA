#include <stdio.h>

struct Node
{
	
	struct Node* next;
	int data;
}

typedef struct Node Node;

int main()
{
	struct Node* head ;
	struct Node* temp ;
	for(int i=0;i<n;i++)
	{
		int n;
		scanf("%d",&n);
		if(head == NULL)
		{
			head = new Node(n);
			temp = head;
		}
		else 
		{
			temp->next = new Node(n);
			temp = temp->next;
		}
	}

	while(head)
	{
		printf("%d " , head->data);
		head = head->temp;
	}
	return 0;

}
