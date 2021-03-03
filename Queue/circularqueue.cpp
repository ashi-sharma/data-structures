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
			rear=front=0;size=10;q = new int[size];
		}
		queue(int size){
			rear=front=0;this->size=size;q = new int[size];
		}
		void enqueue(int x);
		int dequeue();
		void display();
};
void queue::enqueue(int x){
	if((rear+1)%size==front){
		cout<<"queue is full";
	}
	else{
		rear = (rear+1)%size;
		q[rear]=x;
	}
}
int queue::dequeue(){
	int x=-1;
	if(rear==front){
		cout<<"queue is empty";
	}
	else{
		front = (front+1)%size;
		x=q[front];
	}
	return x;
}
void queue::display(){
	int i=front+1;
	do{
		cout<<q[i]<<" ";
		i=(i+1)%size;
	}while(i!=(rear+1)%size);
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
