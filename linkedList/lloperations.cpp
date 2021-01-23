#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
};

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
};
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
linkedlist::~linkedlist(){
	node *p;
	p=first;
	while(first){
		first=first->next;
		delete p;
		p=first;
	}
}
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

void linkedlist::display(){
	node *p;
	p=first;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
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
int linkedlist::length(){
	node *p=first;
	int len=0;
	while(p){
		len++;
		p=p->next;
	}
	return len;
}

int main(){
	int a[3]={7,10,13};
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
	return 0;
}
