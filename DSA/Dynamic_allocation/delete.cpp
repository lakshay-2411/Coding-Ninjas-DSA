//Static memory: auto release on the basis of scope
//Dynamic memory: manual release is required using "delete" keyword

#include <iostream>
using namespace std;

int main(){

    //In case of single element
    int* p = new int;
    delete  p;      //Deletes the memory on the heap not on stack

    p = new int;
    delete p;       //P is not getting deleted but wherever p is pointing to gets deleted

    //In case of Array
    p = new int[100];
    delete [] p;
}