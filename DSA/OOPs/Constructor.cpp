#include <iostream>
#include "Student.cpp"
using namespace std;

int main(){
    Student s1(1004,24);
    cout << "Address of S1 : " << &s1 << endl;
    
    Student s2(203);
    s2.display();






    /*
    Student s1;
    s1.display();


    Student *s2 = new Student;
    s2 -> display();

    cout << "Parametrized Constructor demo " << endl;
    Student s3(20);
    s3.display();

    Student *s4 = new Student(100);
    s4 -> display();

    Student s6(1004,29);
    s6.display();
    */
}