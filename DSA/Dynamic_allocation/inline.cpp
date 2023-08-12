//ways to find maximum of two numbers


#include <iostream>
using namespace std;

inline int max(int a,int b){
    return (a > b) ? a : b;
}

int main(){


    //basic code
    int a,b;
    cin >> a >> b;
    /*
    int c;
    if(a>b){
        c = a;
    } else{
        c = b;
    }  */



    // 2ND -> By using TERTIARY OPERATOR    (condition)? result(true):else
    /*
    int c = (a > b) ? a : b;
    int x,y;
    x=12,y=34;
    int z = (x > y) ? x: y;
    // In this we have to use this code for many times if we want to find maximum a number of times
    */



   //3RD -> By using this tertiary operator in functions
   // this is a much better code and now its readability becomes very very good 
   /*
   int c = max(a,b);

    int x,y;
    x=12,y=34;
    int z = max(x,y);

    //In this code readability is good but there is a issue in performance as there is fxn calling and copying of variables
    */


   //4TH -> We want the best of both the scenarios : Best performance and Best readability
   // To do this we will use the same code as in 3RD but we will make our function INLINE   ->   inline int max(int a, int b)

    int c = max(a,b);
    cout << c << endl;
    int x,y;
    x=12,y=34;
    int z = max(x,y);
    cout << z << endl;

//The use of inline function is that where we will call the inline function the body of that inline function will be copied there,
//so there will be no copying of variables or function calling


//In INLINE function the body must be of 2 or maximum 3 lines otherwise compiler will not work as inline function

}