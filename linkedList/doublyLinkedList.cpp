#include<iostream>
using namespace std;
//class node
class node{
	public:
		int data;
		node *next;
		node *prev;
};
//class doubly linked list
class dlinkedlist{
	public:
		node *first;
		dlinkedlist(){
			first=NULL;
		}
		~dlinkedlist();
		dlinkedlist(int arr[],int n);
		void display();
		void insert(int num,int index);
};
//insert an element at an index
void dlinkedlist::insert(int num,int index){
	node *t=new node;
	t->data=num;
	if(index==0){
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
		return;
	}
	node*p=first->next;
	int i=1;
	while(index>i){
		p=p->next;
		i++;
	}
	t->next=p;
	t->prev=p->prev;
	p->prev->next=t;
	p->prev=t;
	
}
//display elements of doubly linked list
void dlinkedlist::display(){
	node *p=first;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
}
//destructor
dlinkedlist::~dlinkedlist(){
	node *p=first;
	while(first){
		first=p->next;
		delete p;
		p=first;
	}
}
//parameterised constructor
dlinkedlist::dlinkedlist(int arr[],int n){
	first=new node;
	node *t,*p;
	first->prev=NULL;
	first->data=arr[0];
	p=first;
	for(int i=1;i<n;i++){
		p->next=new node;
		t=p;
		p=p->next;
		p->prev=t;
		p->data=arr[i];
	}
	p->next=NULL;
}
//main function
int main(){
	
	int arr[5]={1,2,3,4,5};
	dlinkedlist dll(arr,5);
	dll.insert(9,5);
	dll.display();
	return 0;
	
}
