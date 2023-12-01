#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    TrieNode* next[2];
    TrieNode() {
        next[0] = next[1] = nullptr;
    }
};

class Trie {

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->next[bit]) {
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }

	
    int findMaxXOR(int num) {
        TrieNode* node = root;
        int result = 0;

        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int flipBit = 1 - bit;

            if (node->next[flipBit]) {
                result |= (1 << i);
                node = node->next[flipBit];
            } else {
                node = node->next[bit];
            }
        }

        return result;
    }


};


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){

	//	Write your coode here.

	sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>off;
    int n=queries.size();
    for(int i=0;i<n;i++){
      off.push_back({queries[i][1],{queries[i][0],i}});
    }
    vector<int>ans(n,0);
    Trie trie;
    sort(off.begin(),off.end());
    int i=0;
    for(auto x:off){
        int ai=x.first;
        int xi=x.second.first;
        int ind=x.second.second;
        for(;i<arr.size();i++){
            if(arr[i]<=ai)
              trie.insert(arr[i]);
              else
              break;
        }
        if(i==0)
        ans[ind]=-1;
        else {
        int xor1 = trie.findMaxXOR(xi);
        ans[ind] = xor1;
        }
    }
    return ans;
}