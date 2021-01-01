//***********Cyclically rotate an array by one************ 

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int temp=a[n-1];
	    for(int j=n-1;j>0;j--){
	        a[j]=a[j-1];
	    }
	    a[0]=temp;
	    for(int k=0;k<n;k++)
	        cout<<a[k]<<" ";
	    cout<<endl;
	}
	return 0;
}

//************Minimise the maximum difference between the heights through increasing or decreasing them by k************

//************Minimum number of jumps to reach end of the array***************
