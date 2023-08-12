#include <iostream>
#include "Student.cpp"
using namespace std;

int main(){
    Student s1(20,1001);
    cout << "S1's :" ;
    s1.display();

    Student s2(s1);
    cout << "S2's :" ;
    s2.display();

/*
    Student *s3 = new Student(10,2001);
    cout << "S3's :" ;
    s3 -> display();

    Student s4(*s3);
    cout << "S4's :" ;
    s4.display();

    Student *s5 = new Student(*s3);
    cout << "S5's :" ;
    s5 -> display();

    Student *s6 = new Student(s1);
    cout << "S6's :" ;
    s6 -> display();
    */
            // USE OF COPY ASSIGNMENT OPERATOR

/*

    Student s3(13,274);
    cout << "S3's :" ;
    s3.display();

    Student *s4 = new Student(25,654);
    cout << "S4's before copy :" ;
    s4 -> display();

    *s4 = s3;
    cout << "S4's after copy :" ;
    s4 -> display();

    */

   // We can use copy constructor in this way also
    Student s5 = s1;

}