#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l,int r){
	
	int pivot = a[r];
	int i= l-1;

	for(int j=l; j<=r-1; j++){
		if(a[j] < pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

int find_kth(vector<int> &a, int l, int r, int k) {

	int p = partition(a,l,r);
	if(p==k)
		return a[p];
	else if(p>k)
		return find_kth(a,l,p-1,k);
	else
		return find_kth(a,p+1,r,k);
}

int main(){

	int n,k;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int> a(n);
	cout<<"enter k (1...n): ";
	cin>>k;
	cout<<"enter the elements seperated by space--\n ";
	for(int i=0;i<n;i++)
		cin>>a[i];

	int kmin = find_kth(a,0,n-1,k-1);
	int kmax = find_kth(a,0,n-1,n-k);

	cout<<k<<"th minimum element is: "<<kmin<<"\n";
	cout<<k<<"th maximum element is: "<<kmax<<"\n";
	return 0;

}
