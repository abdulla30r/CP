#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];

void merge(int l,int r,int mid){
	int l_sz = mid - l + 1;
	int L[l_sz+1];

	int r_sz = r-mid;
	int R[r_sz+1];

	//left array
	for(int i=0;i<l_sz;i++){
		L[i] = a[l+i];
	}

	//right array
	for(int i=0;i<r_sz;i++){
		R[i] = a[mid+i+1];
	}

	//last element e ekta extra big value rakha. jate merge korar somoy extra value beche na jay. sob use hoy
	L[l_sz] = R[r_sz] = INT_MAX;


	int l_i = 0;
	int r_i = 0;

	//merge
	for(int i=l;i<=r;++i){
		if(L[l_i]<=R[r_i]){
			a[i] = L[l_i];
			l_i++;
		}else{
			a[i] = R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int l, int r){
	if (l==r) return;
	int mid = (l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	merge(l,r,mid);
}


int main(){
	int n;
	cin >>n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	mergeSort(0,n-1);

	for(int i=0;i<n;i++){
		cout <<a[i] <<" ";
	}
}