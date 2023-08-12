#include "TrieNode.h"
#include <vector>
#include <cstring>
using namespace std;

class Trie{
    TrieNode* root;

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, string word){
        //Base case
        if(word.size()==0){
            root->isTerminal = true;
            return;
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
        insertWord(child,word.substr(1));
    }

    //For User
    void insertWord(string word){
        insertWord(root,word);
    }

    bool searchWord(TrieNode* root, string word){
        if(word.size() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            return searchWord(root->children[index],word.substr(1));
        }else{
            return false;
        }
    }

    bool searchWord(string word){
        return searchWord(root,word);
    }

    void removeWord(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            // word not found
            return;
        }
        removeWord(child,word.substr(1));

        // Remove child node if it is useless
        if(child -> isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word){
        removeWord(root,word);
    }

    bool helper(TrieNode* root, string word){
        if(word.size() == 0){
            return true;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            return helper(root->children[index],word.substr(1));
        }else{
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool searchPrefix(string prefix) {
        return helper(root,prefix);
    }


    void insertSuffixes(string word){
        for(int i=0;i<word.size();i++){
            insertWord(word.substr(i));
        }
    }
};