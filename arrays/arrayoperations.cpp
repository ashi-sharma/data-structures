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
		void append(T ele);
		int linsrch(T key);
		int binarysearch(T ele);
		T get(int index);
		void set(int index, T e);
		T sum();
};

template <class T>
T array<T>::sum(){
	T s=0;
	for(int i=0;i<length;i++){
		s=s+a[i];
	}
	return s;
}

template <class T>
T array<T>::get(int index){
	if(index<length){
		return a[index];
	}
}

template <class T>
void array<T>::set(int index, T e){
	if(index<=length){
		a[index] = e;
	}
	display();
}

template <class T>
int array<T>::binarysearch(T ele){
	int first = 0,last = length-1,mid = last/2;
	while(mid<last && mid>first){
		if(a[mid] == ele)
			return mid;
		else if(a[mid]<ele){
			first = mid+1;
			mid = (last + first)/2;
		}
		else{
			last = mid-1;
			mid = (last+first)/2;
		}
	}
	return -1;
}

template<class T>
int array<T>::linsrch(T key){
	if(length>0){
		for(int i=0;i<length;i++){
			if(key == a[i])
			return i;
		}
	}
	return -1;
}

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

template<class T>
void array<T>::append(T ele){
	if(length<size){
		a[length] = ele;
		length++;
	}
	display();
}

int main() {
	array<int> arr;
	int choice,ind;
	int num;          
	do{
		cout<<"******MAIN MENU*******"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Append"<<endl;
		cout<<"4. Linear search"<<endl;
		cout<<"5. Binary search"<<endl;
		cout<<"6. Display"<<endl;
		cout<<"7. Reverse"<<endl;
		cout<<"8. Minimum element"<<endl;
		cout<<"9. Maximum element"<<endl;
		cout<<"10. Sum"<<endl;
		cout<<"11. Get"<<endl;
		cout<<"12. Set"<<endl;
		cout<<"13. Exit"<<endl;
		cout<<"Enter Your choice:"<<endl;
		cin>>choice;
		switch(choice){
			case 1: cin>>ind>>num;
					arr.insert(ind,num);
					break;
			case 2: cin>>ind;
					cout<<arr.del(ind)<<"  deleted!"<<endl;
					break;
			case 3: cin>>num;
					arr.append(num);
					break;
			case 4: cin>>num;
					cout<<"found at "<<arr.linsrch(num)<<endl;
					break;
			case 5: cin>>num;
					cout<<"element found at "<<arr.binarysearch(num)<<endl;
					break;
			case 6: arr.display();
					break;
			case 7: arr.reverse();
					break;
			case 8: cout<<arr.min()<<endl;
					break;
			case 9: cout<<arr.max()<<endl;
					break;
			case 10: cout<<arr.sum()<<endl;
					 break;
			case 11: cin>>ind;
					 cout<<arr.get(ind)<<endl;
					 break;
			case 12: cin>>ind>>num;
					 arr.set(ind,num);
					 break;
		}
	}while(choice<13);
	return 0;
}
