#include<iostream>
using namespace std;
//class node
class node{
	public:
		int data;
		node *next;
};
//class stack
class stack{
	node *top;
	public:
		stack(){
			top=NULL;
		}
		void push(int ele);
		int pop();
		void display();
};
void stack::push(int ele){
	node *t=new node;
	if(t==NULL)
		cout<<"stack overflow"<<endl;
	else{
		t->data=ele;
		t->next=top;
		top=t; 	
	}
}
void stack::display(){
	node *p=top;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int stack::pop(){
	int x=-1;
	if(top==NULL)
		cout<<"stack underflow"<<endl;
	else{
		x=top->data;
		node *p=top;
		top=top->next;
		delete p;
	}
	return x;
}
int main(){
	stack s;
	s.push(12);
	s.push(10);
	s.push(9);
	s.push(1);
	s.display();
	cout<<s.pop()<<"deleted"<<endl;
	s.display();
	return 0;
}
