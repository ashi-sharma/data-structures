#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};
class queue{
	private:
		node *front;
		node *rear;
	public:
		queue(){
			front=rear=NULL;
		}
		void enqueue(int x);
		int dequeue();
		void display();
};
void queue::enqueue(int x){
	node *t = new node;
	if(t==NULL){
		cout<<"queue overflow"<<endl;
	}
	else{
		t->data=x;
		t->next=NULL;
		if(front==NULL){
			front=t;
			rear=t;
		}
		else{
			rear->next=t;
			rear=t;
		}
	}
}
int queue::dequeue(){
	int x=-1;
	node *p;
	if(front==NULL){
		cout<<"queue is empty"<<endl;
	}
	else{
		p=front;
		front=p->next;
		x=p->data;
		delete p;
	}
	return x;
}
void queue::display(){
	node *p=front;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main(){
	queue q;
	q.enqueue(12);
	q.enqueue(11);
	q.display();
	cout<<q.dequeue()<<"deleted"<<endl;
	q.enqueue(16);
	q.enqueue(17);
	q.display();
	return 0;
}
