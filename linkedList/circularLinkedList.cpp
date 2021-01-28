#include<iostream>
using namespace std;
//class node
class node{
	public:
		int data;
		node *next;
};
//class circular linked list
class circularlinkedlist{
	public:
		node *head;
		circularlinkedlist(){
			head=NULL;
		}
		~circularlinkedlist();
		circularlinkedlist(int arr[],int n);
		void display();
};
//destructor
circularlinkedlist::~circularlinkedlist(){
	node *p=head;
	while(head){
		head=p->next;
		delete p;
		p=head;
	}
}
//parameterised constructor definition
circularlinkedlist::circularlinkedlist(int arr[],int n){
	head=new node;
	head->data=arr[0];
	head->next=head;
	node *p=head,*t;
	for(int i=1;i<n;i++){
		t=new node;
		t->data=arr[i];
		p->next=t;
		t->next=head;
		p=t;
	}
}
//display elements of circular linked list
void circularlinkedlist::display(){
	node *p=head;
	do{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
}
//main function
int main(){
	int arr[5]={2,7,8,10,13};
	circularlinkedlist cll(arr,5);
	cll.display();
	return 0;
	}
