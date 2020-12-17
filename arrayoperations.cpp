#include <iostream>
using namespace std;

template <class T>
class array{
	private:
		T *a;
		int size;
		int length;
	public:
		array(){
			a = new T[10];
			size = 10;
			length = 0;
		}
		
		array(int sz){
			a = new T[sz];
			size = sz;
			length = 0;
		}
		
		~array(){
			delete []a;
		}
		
		void display();
		void insert(int index,T num);
		T del(int index);
};

template<class T>
void array<T>::display(){
	for(int i = 0;i<length;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

template<class T>
void array<T>::insert(int index,T num){
	if(index>=0 && index<=length){
	
		for(int i=length-1;i>=index;i++){
			a[i+1]=a[i];
		}
		a[index] = num;
		length++;
	}
}

template<class T>
T array<T>::del(int index){
	T x = 0;
	if(index>=0 && index<length){
		x = a[index];
		for(int i=index;i<length;i++){
			a[i] = a[i+1];
		}
		length--;
	}
	return x;
}

int main() {
	array<char> arr;
	arr.insert(0,'a');
	arr.insert(1,'e');
	arr.insert(2,'c');
	arr.display();
	cout<<arr.del(1)<<endl;
	arr.display();
	return 0;
}
