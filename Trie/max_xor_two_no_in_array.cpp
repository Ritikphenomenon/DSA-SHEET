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

int maximumXor(vector<int>& nums) {
    Trie trie;
    int maxXOR = 0;

    // Build the trie
    for (int num : nums) {
        trie.insert(num);
    }

    // Find maximum XOR
    for (int num : nums) {
        maxXOR = max(maxXOR, trie.findMaxXOR(num));
    }

    return maxXOR;
}
