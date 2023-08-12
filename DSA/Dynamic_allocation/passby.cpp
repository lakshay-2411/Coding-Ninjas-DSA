#include<iostream>
using namespace std;

void increment(int& n){
    n++;
}

//IF WE ARE RETURNING THE REFERENCE OR POINTER OF A LOCAL VARIABLE OF A FUNCTION THEN WE ARE DOING A BIG MISTAKE!!!
//BECAUSE THE SCOPE OF THAT VARIABLE HAS BEEN FINISHED SO, THE ADDRESS WILL ALSO GET FINISHED

//BAD PRACTICE
int& f(int n){
    int a = n;
    return a;
}

//BAD PRACTICE
int* f2(){
    int i = 10;
    return& i; 
}

int main(){
    int* p = f2();

    int i =10;

    int& k = f(i);

    increment(i);
    cout << i << endl;
}