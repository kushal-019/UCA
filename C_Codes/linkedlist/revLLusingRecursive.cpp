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

Node* revList(Node* head)
{
	if(!head || !head->next)return head;
	Node* newHead = revList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
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
	cin>>n;
	Node* head = NULL;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		head = createList(head , x);
	}
	head = revList(head);
	printlist(head);
	return 0;
}
