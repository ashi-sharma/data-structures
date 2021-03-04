#include<iostream>
using namespace std;
//class stack
class stack{
	int top;
	int size;
	int *s;
	public:
		stack(){
			top=-1;size=10;s=new int[size];
		}
		stack(int size){
			top=-1;this->size=size;s=new int[size];
		}
		void push(int ele);
		int pop();
		int peek(int p);
		int stacktop();
		int isempty();
		int isfull();
		void display();
};
void stack::push(int ele){
	if(top==size-1){
		cout<<"stack overflow"<<endl;
	}
	else{
		top++;
		s[top]=ele;
	}
}
int stack::pop(){
	int x=-1;
	if(top==-1){
		cout<<"stack underflow"<<endl;
	}
	else{
		x=s[top];
		top--;
	}
	return x;
}
int stack::peek(int p){
	int x=-1;
	if(top-p+1<0){
		cout<<"position invalid"<<endl;
	}
	else{
		x=s[top-p+1];
	}
	return x;
}
int stack::stacktop(){
	if(top==-1){
		cout<<"stack underflow"<<endl;
		return -1;
	}
	else{
		return s[top];
	}
}
int stack::isempty(){
	if(top==-1)
		return 1;
	else
		return 0;
}
int stack::isfull(){
	if(top==size-1)
		return 1;
	else
		return 0;
}
void stack::display(){
	for(int i=top;i>=0;i--){
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
int main(){
	stack st(8);
	st.push(8);
	st.push(3);
	st.push(9);
	st.push(12);
	st.push(7);
	st.display();
	return 0;
}
