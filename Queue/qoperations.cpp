#include<iostream>
using namespace std;
//class queue
class queue{
	private:
		int rear;
		int front;
		int size;
		int *q;
	public:
		queue(){
			rear=front=-1;size=10;q = new int[size];
		}
		queue(int size){
			rear=front=-1;this->size=size;q = new int[size];
		}
		void enqueue(int x);
		int dequeue();
		void display();
};
void queue::enqueue(int x){
	if(rear==size-1){
		cout<<"queue is full";
	}
	else{
		q[++rear]=x;
	}
}
int queue::dequeue(){
	int x=-1;
	if(rear==-1){
		cout<<"queue is empty";
	}
	else{
		x=q[front+1];
		front++;
	}
	return x;
}
void queue::display(){
	for(int i=front+1;i<=rear;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
int main(){
	queue Q(5);
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.display();
	cout<<"element deleted"<<Q.dequeue()<<endl;
	Q.display();
	return 0;
}
