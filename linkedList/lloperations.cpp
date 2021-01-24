#include<iostream>
using namespace std;
//class node
class node{
	public:
		int data;
		node *next;
};
//class linked list
class linkedlist{
	public:
		node *first;
		linkedlist(){
			first=NULL;
		}
		linkedlist(int arr[],int n);
		~linkedlist();
		int insert(int index,int num);
		void display();
		int Delete(int index);
		int length();
		void reverse();
		int issorted();
		int s_insert(int num);
		void remove_duplicate();
		node* rec_reverse(node*p,node*t);
};
//recursive reverse of linkedlist
node* rec_reverse(node*p,node*t){
	if()
}
//remove duplicate nodes of linkedlist
void linkedlist::remove_duplicate(){
	node *p,*t;
	t=first;
	p=first->next;
	while(p){
		if(p->data==t->data){
			t->next=p->next;
			delete p;
			p=t->next;
		}
		else{
			t=p;
			p=p->next;
		}
	}
}
//insert in a sorted linked list
int linkedlist::s_insert(int num){
	int index=0;
	node *n = new node;
	node *t, *p;
	n->data=num;
	n->next=NULL;
	if(num<first->data){
		n->next=first;
		first=n;
		return index;
	}
	index++;
	t=first;
	p=first->next;
	while(p){
		if(p->data > num){
			n->next=p;
			t->next=n;
			return index;
		}
		index++;
		t=p;
		p=p->next;
	}
	t->next=n;
	return index;
}
//Check if the linkedlist is sorted
int linkedlist::issorted(){
	node *p;
	p=first;
	while(p->next!=NULL){
		if(p->data > (p->next)->data)
			return -1;
		p=p->next;
	}
	return 0;
}
//parameterized constructor
linkedlist::linkedlist(int arr[],int n){
	first=new node;
	node *last,*t;
	t=first;
	last=first;
	first->data=arr[0];
	first->next=NULL;
	for(int i=1;i<n;i++){
		last=new node;
		last->data=arr[i];
		last->next=NULL;
		t->next=last;
		t=last;
	}
}
//Destructor
linkedlist::~linkedlist(){
	node *p;
	p=first;
	while(first){
		first=first->next;
		delete p;
		p=first;
	}
}
//insert at an index of linked list
int linkedlist::insert(int index,int num){
	node *n = new node;
	int i=0;
	node *t, *p;
	n->data=num;
	n->next=NULL;
	if(index==0){
		n->next=first;
		first=n;
		return num;
	}
	p=first;
	while(p){
		if(i==index){
			n->next=t->next;
			t->next=n;
			return num;
		}
		i++;
		t=p;
		p=p->next;
	}
}
//display all the elements of linked list
void linkedlist::display(){
	node *p;
	p=first;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//Delete a node at given index
int linkedlist::Delete(int index){
	node *p,*t;
	int num;
	p=first;
	if(index==0){
		num=first->data;
		first=first->next;
		delete p;
		return num;
	}
	t=first;
	p=first->next;
	for(int i=1;i<length();i++){
		if(i==index){
			num=p->data;
			t->next=p->next;
			delete p;
			return num;
		}
		t=p;
		p=p->next;
	}
}
//length of a linked list
int linkedlist::length(){
	node *p=first;
	int len=0;
	while(p){
		len++;
		p=p->next;
	}
	return len;
}
//Reverse a linkedlist
void linkedlist::reverse(){
	if(length()==1)
		return;
	node *p,*t,*m;
	t=first;
	m=t->next;
	p=m->next;
	t->next=NULL;
	while(m){
		
		m->next=t;
		t=m;
		m=p;
		if(p!=NULL)
			p=p->next;
	}
	first=t;
}
//Main function
int main(){
	int a[3]={7,10,13};
	cout<<"a"<<endl;
	linkedlist ll(a,3); 
	cout<<"inserting 6"<<endl;
	ll.insert(1,6);
	ll.display();
	cout<<"inserting 8"<<endl;
	ll.insert(2,8);
	ll.display();
	cout<<endl<<"length = "<<ll.length()<<endl;
	ll.Delete(2);
	ll.display();
	cout<<endl<<"length = "<<ll.length()<<endl;
	int arr[4]={8,6,2,2};
	linkedlist l(arr,4);
	l.display();
	l.reverse();
	cout<<"reverse done: ";
	l.display();
	cout<<l.issorted();
	cout<<endl<<"7 inserted at index "<<l.s_insert(7)<<endl;
	l.display();
	l.remove_duplicate();
	l.display();
	l.rec_reverse(l.first->next,l.first)
	return 0;
}
