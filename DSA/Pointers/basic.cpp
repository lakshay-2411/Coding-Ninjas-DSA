#include <iostream>
using namespace std;
int main(){
   /* int i=10;
    cout << &i << endl;   // & gives address of variable
    int * p = &i;
    cout << p << endl;
    // we can use dereference operator to get the value of i through p
    cout << *p << endl;

    */

/*
    float f = 10.2;
    float * pf = &f;

    double d = 122.32;
    double * pd = &d;
    */

  /* int i=10;
   int * p = &i; */
   /*
   cout << sizeof(i) << " " << sizeof(p) << endl;
   cout << i << " " << *p << endl;
   i++;
   cout << i << " " << *p << endl;

   int a = *p;
   a++;
   cout << a << " " << *p;
   */
/*


   i = 12;
   cout << i << " " << *p << endl;
   *p = 23;
   cout << i << " " << *p << endl;
   (*p)++;
   cout << i << " " << *p << endl;

   // I can write this also 
   int *q = p;      // this means q is containing the address of i

   // *P , *Q AND I, THEY ALL ARE DIFFERENT PATHS TO REACH AT SAME POINT
*/ 

/*      int i;
cout << i << endl;
i++;
cout << i << endl;    */

/*
int * p;
cout << p << endl;

cout << *p << endl;     //PLEASE DON'T DO THIS!!
(*p)++;                 // THIS WILL INCREASE 1 IN SOME MEMORY LOCATION WHICH CAN BE OURS OR NOT ALSO
cout << *p << endl;
*/

// STORE EITHER ADDRESS OF SOMETHING IN POINTER AND IF YOU DON'T HAVE ANYTHING TO STORE THEN GIVE IT A ZERO
// THIS IS KNOWN AS NULL POINTER 

int * p = 0;
cout << p << endl;

cout << *p << endl;         //THIS WILL DEFINITELY GIVE US ERROR AS THERE IS NO SUCH ADDRESS AVAILABLE
(*p)++;                
cout << *p << endl;

}