#include <iostream>
#include "Student.cpp"
using namespace std;

int main(){
    Student s1(15,1001);
    Student s2(20,2001);

        // IN THIS WE WILL SEE DESTRUCTOR WILL BE CALLED TWO TIMES ONLY BCZ ONE OBJECT IS DYNAMICALLY MADE
        // TO DEALLOCATE THE DYNAMICALLY MADE OBJECT WE'LL HAVE TO USE DELETE KEYWORD

    Student *s3 = new Student(30,3001);

    delete s3;
}