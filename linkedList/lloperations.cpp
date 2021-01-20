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
		void insert(int index,int num);
		void display();
		void Delete(int index);
		void length();
};
linkedlist::linkedlist(int arr[],int n){
	first=new node;
	node *last,*t;
	t=first;
	last=first;
	for(int i=0;i<n;i++){
		t->data=arr[i];
		last=new node;
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
void linkedlist::insert(int index,int num){
	node *n = new node;
	int i=0;
	node *t, *p;
	n->data=num;
	n->next=NULL;
	p=first;
	while(p){
		if(i==index){
			n->next=t->next;
			t->next=n;
			break;
		}
		i++;
		t=p;
		p=p->next;
	}
}

void linkedlist::display(){
	node *p;
	p=first;
	while(p->next!=NULL){
		cout<<p->data<<" ";
	}
}
		void Delete(int index);
		void length();

int main(){
	int a[1]={7};
	linkedlist ll(a,1); 
	cout<<"inserting 6"<<endl;
	ll.insert(1,6);
	ll.display();
	cout<<"inserting 8"<<endl;
	ll.insert(2,8);
	ll.display();
	ll.insert(3,2);
	ll.insert(4,5);
	ll.insert(5,1);
	ll.display();
	return 0;
}
