#include <iostream>
#include "templates.cpp"
using namespace std;

int main(){
    //For making triplet using Pair class
    
    // we can use this also: Pair<int, Pair<double,char>> p5;

    Pair<Pair<int,int>,int> p2;   //As X is a Pair itself so we need to pass pair in setX
    p2.setY(10);
    Pair<int,int> p4;
    p4.setX(15);
    p4.setY(16);
    p2.setX(p4);        //passed pair
    
    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << endl;



    /*
    Pair<int,double> p1;
    p1.setX(100.34);
    p1.setY(100.34);
    cout << p1.getX() << " " << p1.getY() << endl;
    */

    /*
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);
    cout << p1.getX() << " " << p1.getY() << endl;
    Pair<double> p2;
    p2.setX(100.34);
    p2.setY(23.32);
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
    */
}