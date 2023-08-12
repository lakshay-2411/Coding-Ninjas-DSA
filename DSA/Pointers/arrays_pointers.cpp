#include <iostream>
using namespace std;

int main(){
    int a[10];
    /*
    cout << a << endl;
    cout << &a[0] << endl;
    a[0] = 5;
    a[1] = 10;
    cout << *a << endl;
    cout << *(a+1) << endl;
    */

   /*
   for(int i=0;i<10;i++){
    cout << *(a+i) << endl;
   }
   */


    int *p = &a[0];
    cout << a << endl;
    cout << p << endl;

    cout << &p << endl;
    cout << &a << endl;

    cout << sizeof(p) << endl;
    cout << sizeof(a) << endl;

    p = p + 1;        // we can reassign the values in pointer
    a = a + 1;        // we can't reassign the values in arrays...this will always give an error   OR
    a++;              // we can't reassign the values in arrays...this will always give an error
    p = a + 1;        // we can do this instead of above line






}