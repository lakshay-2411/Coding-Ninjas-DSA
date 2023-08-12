#include "TrieClass.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Trie t;
    /*
    t.insertWord("abc");
    t.insertWord("def");
    t.insertWord("ghi");
    t.insertWord("cba");
    t.insertWord("bye");
    t.insertWord("no");
    */

    t.insertSuffixes("abc");
    t.insertSuffixes("def");
    t.insertSuffixes("ghi");
    t.insertSuffixes("cba");
    t.insertSuffixes("bye");
    t.insertSuffixes("no");

    cout << t.searchPrefix("hi") << endl;

    // t.removeWord("bye");
    // cout << t.searchWord("bye");

}