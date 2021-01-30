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
};
//destructor
dlinkedlist::~dlinkedlist(){
	
}
//parameterised constructor
dlinkedlist::dlinkedlist(int arr[],int n){
	
}
//main function
int main(){
	return 0;
}
