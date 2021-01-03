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

int minJumps(int arr[], int n){
    int minjump[n]={10000001};
    cout<<minjump[1];
    minjump[0]=0;
    cout<<endl<<INT_MAX<<" "<<minjump[2];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i<=j+arr[j]){
                minjump[i]=std::min(minjump[i],minjump[j]+1);
            }
        }
    }
    //if(minjump[n-1]==INT_MAX)
    //    return -1;
    return minjump[n-1];
}
