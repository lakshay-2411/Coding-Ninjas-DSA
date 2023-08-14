//#include "TrieClass.h"
//#include "autoComplete.h"
#include "palindromePair.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Trie t;
    int n;
    cin >> n;

    vector<string> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    cout << (t.isPalindrome(v) ? "true" : "false");









/*
    vector<string> v;
    for(int i=0;i<n;i++){
        string word;
        cin >> word;
        v.push_back(word);
    }
    string pattern;
    cin >> pattern;

    t.autoComplete(v,pattern);

*/






    /*
    t.insertWord("abc");
    t.insertWord("def");
    t.insertWord("ghi");
    t.insertWord("cba");
    t.insertWord("bye");
    t.insertWord("no");
    */


/*
    t.insertSuffixes("abc");
    t.insertSuffixes("def");
    t.insertSuffixes("ghi");
    t.insertSuffixes("cba");
    t.insertSuffixes("bye");
    t.insertSuffixes("no");

    cout << t.searchPrefix("hi") << endl;

*/    

    // t.removeWord("bye");
    // cout << t.searchWord("bye");

}