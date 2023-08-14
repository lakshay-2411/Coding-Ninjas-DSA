#include "TrieNode.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Trie{
    TrieNode* root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode* root, string word){
        //Base case
        if(word.size()==0){
            if(!root->isTerminal){
                root->isTerminal = true;
                return true;
            }else{
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child,word.substr(1));
    }

    //For User
    void insertWord(string word){
        insertWord(root,word);
    }

    bool searchPalindrome(TrieNode* root,string word){
        if(root->isTerminal || word.size() == 0){
            return true;
        }
        if(root->children[word[0] - 'a'] != NULL){
            return searchPalindrome(root->children[word[0] - 'a'],word.substr(1));
        }else{
            return false;
        }
    }

    bool searchPalindrome(vector<string> words){
        for(int i=0;i<words.size();i++){
            string s1 = words[i], s2 = words[i];
            reverse(s1.begin(),s1.end());
            if(searchPalindrome(root,s1)){
                return true;
            }
        }
        return false;
    }

    bool isPalindrome(vector<string> v){
        for(int i=0;i<v.size();i++){
            insertWord(v[i]);
        }

        return searchPalindrome(v);
    }
};