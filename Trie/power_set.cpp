#include <bits/stdc++.h> 
using namespace std;


void solve(int i, vector<int>&v, vector<vector<int>>&ans,vector<int>&temp) {

	if (i == v.size()) {
		ans.push_back(temp);
		return;
	}

	//picking 
	temp.push_back(v[i]);

	solve(i + 1, v,  ans,temp);

	//poping out while backtracking

	temp.pop_back();

	solve(i + 1, v,ans,temp);

}



vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here

    vector<vector<int>>ans;
    vector<int>temp;
    solve(0,v,ans,temp);
    return ans;

}