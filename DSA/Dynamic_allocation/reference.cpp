#include <iostream>
using namespace std;

int main(){
    /*
    int i = 10;
    int j = i;
    i++;
    cout << j << endl;      //This will not affect j. It will be 10 only
    */

    //We have to make only one memory allocation means no memory allocation for j.
    //For this we'll use '&'(impascent) reference operator. This  will give the address of already allocated memory and not make a new one.

    int i = 10;
    int& j = i;
    i++;
    cout << j << endl;
    j++;
    cout << i << endl;

    int k = 90;
    j = k;      //This is only copying. We have to give space to reference variable at the starting point only
    cout << i << endl;
    cout << j << endl;

}