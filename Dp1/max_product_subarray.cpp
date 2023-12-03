#include <bits/stdc++.h>

void solve(vector<int>&arr,int ind,int n,int &ans,int prod){

	if(ind==n){
		if(prod>=ans){
			ans=prod;
			return;
		}
		else{
			return;
		}
	}
   

   solve(arr,ind+1,n,ans,prod*arr[ind]);
   
   solve(arr,ind+1,n,ans,prod);
   
}

int maximumProduct(vector<int> &arr, int n) {
  // Write your code here
  int ans = INT_MIN;
  int prod=1;
  solve(arr,0,n,ans,prod);
  return ans;
}
