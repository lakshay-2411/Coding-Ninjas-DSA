#include <iostream>
using namespace std;

int main(){

//For dynamic memory allocation we use the keyword "new", it gives us the  memory address of that variable and therefore is stored in a pointer variable
    int* p = new int;
    *p = 10;
    cout << *p << endl;
    
    double *pd  = new double;
    char* pc = new char;

    //Find max in Arrays using dynamic allocation

    int* pa = new int[50];
    int n;
    cout << "Enter number of elements " << endl;
    cin >> n;

    int* pa2 = new int[n];
    for(int i=0; i<n; i++){
        cin >> pa2[i];
    }
    int max = -1;
    for(int i=0; i<n; i++){
        if(max<pa2[i]){
            max = pa2[i];
        }
    }
    cout << max << endl;

    


}