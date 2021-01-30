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
		void insert(int num,int index);
		void del(int index);
};
//to delete an element from circular linked list
void circularlinkedlist::del(int index){
	node*p,*t;
	p=head;
	if(index==0){
		while(p->next!=head){
			p=p->next;
		}
		p->next=head->next;
		delete head;
		head=p->next;
		return ;
	}
	for(int i=0;i<index;i++){
		t=p;
		p=p->next;
	}
	t->next=p->next;
	delete p;
}
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
	cout<<endl;
}
//insert an element in circular linked list
void circularlinkedlist::insert(int num,int index){
	node *t=new node;
	t->data=num;
	node *p=head;
	if(index==0){
		t->next=head;
		while(p->next!=head){
			p=p->next;
		}
		p->next=t;
		head=t;
		return;
	}
	node *q;
	for(int i=0;i<index;i++){
		q=p;
		p=p->next;
	}
	q->next=t;
	t->next=p;
}
//main function
int main(){
	int arr[5]={2,7,8,10,13};
	circularlinkedlist cll(arr,5);
	cll.display();
	cll.insert(1,0);
	cll.display();
	cll.del(0);
	cll.display();
	return 0;
	}
