#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int 
#include<algorithm>
#include<chrono>

using namespace std;
using namespace std::chrono;

void merge(int *Arr, int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}

void mergeSort(int ar[],int si,int ei){
    if(si>=ei) return ;
    if(si<ei){
        int mid=(si+ei)/2;
        mergeSort(ar,si,mid);
        mergeSort(ar,mid+1,ei);
        merge(ar,si,mid,ei);
    } 
}

int main(){
    
    int size=6;
    int arr[size]={2, 6, 8, 5, 4, 3};
    auto start = high_resolution_clock::now();
    mergeSort(arr,0,size-1);
    auto stop = high_resolution_clock::now();
    for(auto var : arr)
    {
        cout<<var<<' ';
    }
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
return 0;
}