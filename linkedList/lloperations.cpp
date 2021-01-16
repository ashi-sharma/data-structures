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

void linkedlist::insert(int index,int num){
	new node n;
	n.data=num;
	n.next=NULL;
	if(first==NULL){
		first=n;
	}
}

void linkedlist::display(){
	
}
		void Delete(int index);
		void length();

int main(){
	linkedlist ll; 
	ll.insert(0,6);
	ll.insert(1,8);
	ll.insert(2,2);
	ll.insert(3,5);
	ll.insert(4,1);
	return 0;
}
