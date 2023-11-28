/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
#include<bits/stdc++.h>


class TrieNode {

   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

};




class Trie {

public:

    /** Initialize your data structure here. */
     TrieNode *root;
    Trie() {
   root = new TrieNode('\0'); 

    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }


    /** Inserts a word into the trie. */
    void insert(string word) {
         insertWord(root, word); 

    }

bool search(TrieNode *root , string word){

        if(word.size()==0){
            if(root->isTerminal==true){
                return true;
            }
            else{
                return false;
            }
        }
        
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
          child = root->children[index];
         return  search(child, word.substr(1));
        }
        else{
            return false;
        }
        
        }


    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(root,word);
    }

    bool start(TrieNode*root,string prefix){
         if (prefix.size() == 0) {
          return true;
      }
      int index = prefix[0] - 'a';
      TrieNode *child;
      if (root->children[index] != NULL) {
        child = root->children[index];
        return start(child, prefix.substr(1));
      } else {
        return false;
      }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
          return start(root, prefix);

    }
};