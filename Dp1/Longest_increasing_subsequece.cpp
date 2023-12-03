/*
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


*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence


int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    //here the dp solution leads to tle,because it solve the
    //question in o(n2),but we need to solve it in o(nlogn), so i have to
    //used binary search;
    vector<int>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>ans.back())
        ans.push_back(arr[i]);
        else{
            int ind=lower_bound(ans.begin(), ans.end(), arr[i])-ans.begin();
            ans[ind]=arr[i];
        }
    }
    return ans.size();
}
