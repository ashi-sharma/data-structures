#include<iostream>
using namespace std;

void display(int arr[],int n){
	for(int k=0;k<n;k++)
		cout<<arr[k]<<" ";
	cout<<endl;
}

void bubbleSort(int arr[],int n){
	cout<<"bubble sort:"<<endl;
	int temp,f=0;
	for(int i=0;i<n-1;i++){
		display(arr,n);
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				f=1;
			}
		}
		if(f==0)
		break;
	}
}

int main(){
	int arr[5] = {4,6,2,1,3};
	bubbleSort(arr,5);
	return 0;
}
