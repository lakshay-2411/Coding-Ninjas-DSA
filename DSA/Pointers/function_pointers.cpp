#include <iostream>
using namespace std;

void print(int* p){
    cout << *p << endl;
}
void incrementPointer(int* p){  //This fxn will not affect the value of p in main function
    p = p + 1;
}
void increment(int* p){    // THis function will change the value because it is pointing on the address of p
    (*p)++;
}

int main(){
    int i = 10;
    int* p = &i;
    print(p);
    cout << p << endl;
    incrementPointer(p);
    cout << p << endl;

    cout << *p << endl;
    increment(p);
    cout << *p << endl;

}