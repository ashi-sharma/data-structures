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
		void reverse();
		T min();
		T max();
};

template<class T>
T array<T>::min(){
	T min = a[0];
	for(int i = 1;i<length;i++){
		if(a[i]<min)
		min = a[i];
	}
	return min;
}

template<class T>
T array<T>::max(){
	T max = a[0];
	for(int i = 1;i<length;i++){
		if(a[i]>max)
		max = a[i];
	}
	return max;
}

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

template<class T>
void array<T>::reverse(){
	T temp;
	for(int i = 0,j=length-1;i<length/2;i++,j--){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	display();
}

int main() {
	array<int> arr;
	arr.insert(0,1);
	arr.insert(1,6);
	arr.insert(2,4);
	
	arr.display();
	arr.reverse();
	cout<<arr.del(1)<<endl;
	arr.display();
	cout<<"minimum element="<<arr.min()<<endl;
	cout<<"maximum element="<<arr.max()<<endl;
	return 0;
}
