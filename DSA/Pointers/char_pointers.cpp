#include <iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4};
    char b[] = "abc";
    cout << a << endl;
    cout << b[0] << endl;
    cout << b << endl;

    char *c = &b[0];
    cout << c << endl;

    char c1 = 'a';
    char* pc = &c1;

    cout << c1 << endl;
    cout << pc << endl;   // this will goes on printing till it finds the null character

    char str[] = "abcde";    // the most apt way to initialize
    char* pstr = "abcde";    // very wrong way to initialize...sometimes it'll be correct sometimes not!



}