#include<iostream>
using namespace std;
//class node
class node{
	public:
	node *lchild;
	int data;
	node *rchild;
	node(){
		lchild = NULL;
		rchild = NULL;
	}
};
//class tree
class tree{
	public:
	node *root;
	tree(){
		root=NULL;
	}
	
};
int main(){
	
	return 0;
}
