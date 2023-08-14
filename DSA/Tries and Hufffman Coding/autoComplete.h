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

    bool searchWord(TrieNode* root,string word){
        if(word.size() == 0) return true;

        int index = word[0] - 'a';
        if(root->children[index] == NULL) return false;

        return searchWord(root->children[index],word.substr(1));
    }

    bool search(string word){
        return searchWord(root,word);
    }

    void autoComplete(TrieNode* root,string s){
        if(root->isTerminal == true){
            cout << s << endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                char c = i + 'a';
                autoComplete(root->children[i],s+c);
            }
        }
        return;
    }

    void autoComplete(vector<string> v,string pattern){
        for(int i=0;i<v.size();i++){
            insertWord(v[i]);
        }
        if(search(pattern) == false) return;

        string s = pattern;

        while(pattern.size() != 0){
            root = root->children[pattern[0] - 'a'];
            pattern = pattern.substr(1);
        }

        autoComplete(root,s);
    }
};