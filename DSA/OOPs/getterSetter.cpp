#include <iostream>
#include "Student.cpp"
using namespace std;

int main(){
    Student s1;

    Student *s2 = new Student;

    s1.setAge(20);
    s2 -> setAge(24);

    s1.display();
    s2 -> display();
}