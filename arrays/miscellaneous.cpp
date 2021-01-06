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
int minJumps(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

//***********Merge two sorted array without using extra space*************
void merge(int arr1[], int arr2[], int n, int m) {
	    int i=n-1;
	    int j=0;
	    while(arr1[i]>arr2[j] && i>=0 && j<m){
	        swap(arr1[i],arr2[j]);
	        i--;
	        j++;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}

//*********count inversion of an array*********
