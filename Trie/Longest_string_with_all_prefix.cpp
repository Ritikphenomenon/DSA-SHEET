#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans;
    for(int i=0;i<arr[0].size();i++){
        char ch=arr[0][i];
        bool check;
        for(int j=1;j<n;j++){
            if(ch==arr[j][i])
                check=true;
            else{
                check=false;
                break;
            }
        }
        if(check==true){
            ans.push_back(ch);
        }
        else{
            break;
        }
    }
    return ans;
}


