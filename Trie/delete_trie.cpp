#include <bits/stdc++.h> 

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};*/

void deletew(TrieNode* root, string word){
  if(word.size()==0){
     root->isEnd=false;
     return;
  }
  TrieNode *child;
int index = word[0] - 'a';
if(root -> children[index] != NULL) {
child = root -> children[index];
}
else {
return;
}
deletew(child,word.substr(1));

if(child -> isEnd == false) {

for(int i = 0; i < 26; i++) {
if(child -> children[i] != NULL) {
return;
}
}

delete child;

root -> children[index] = NULL;

}


}

TrieNode* solution::deleteWord(TrieNode* root, string word) {
  // Write your code here
  deletew(root,word);
  return root;
}

