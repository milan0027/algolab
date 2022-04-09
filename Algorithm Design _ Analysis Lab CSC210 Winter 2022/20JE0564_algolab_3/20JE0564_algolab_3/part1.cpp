#include <bits/stdc++.h>
using namespace std;

int minimum(vector<int> &a,int l, int r){
	if(l==r) 
	   return a[l];

	int mid=(l+r)/2;
	return min(minimum(a,l,mid),minimum(a,mid+1,r));
}
int maximum(vector<int> &a,int l, int r){
	if(l==r) 
	  return a[l];

	int mid=(l+r)/2;
	return max(maximum(a,l,mid),maximum(a,mid+1,r));
}

int main(){

	int n;
	cout<<"enter the size of the array: ";
	cin>>n;
	vector<int> a(n);
	cout<<"enter the elements of the array seperated by space--\n";
	for(int i=0;i<n;i++)
		cin>>a[i];

	int mini=minimum(a,0,n-1);
	int maxi=maximum(a,0,n-1);

	cout<<"Minimum element is: "<<mini<<"\n";
	cout<<"Maximum element is: "<<maxi<<"\n";
	return 0;
}
