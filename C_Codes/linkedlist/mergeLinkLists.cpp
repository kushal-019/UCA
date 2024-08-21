#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};

Node*  createList(Node* head , int x)
{
	if(!head)
	{       
		head = new Node(x);
		return head ;
	}
	Node* temp = head;
	while(temp->next)temp = temp->next;
	temp->next = new Node(x);
	return head;
}

Node* mergeLists(Node* head1 , Node* head2)
{
	Node* temp = new Node(0);
	Node* ans = temp;

	while(head1 && head2){
		if(head1->data <= head2->data)
		{
			temp->next = head1;
			head1 = head1->next;
		}
		else 
		{
			temp->next = head2;
			head2 = head2->next;
		}
		temp = temp->next;
	}
	if(head1)temp->next = head1;
	if(head2)temp->next = head2;
	return ans->next;
}


void printlist(Node* head)
{
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	return ;
}

int main(){
	int n;
	cout<<"enter first linklist size"<<endl;
	cin>>n;
	Node* head1 = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		head1 = createList(head1 , x);
	}
	cout<<"enter second list size"<<endl;
	cin>>n;
	Node* head2 = NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		head2 = createList(head2 , x);
	}
	Node* temp = NULL;
	temp = mergeLists(head1 , head2);
	printlist(temp);
	return 0;
}
