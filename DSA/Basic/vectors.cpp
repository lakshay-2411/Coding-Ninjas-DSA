#include <iostream>
#include <vector>
using namespace std;

int main(){
    //DYNAMICALLY ALLOCATED VECTOR
    /*vector<int> * vp = new vector<int> (); */

    //STATICALLY ALLOCATED VECTOR
    vector<int> v;
    for(int i = 0;i<100;i++){
        cout << "Capacity: " << v.capacity() << endl;
        cout << "Size: " << v.size() << endl;
        v.push_back(i+1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;

    // '[]' USED ONLY FOR GETTING AND UPDATING ELEMENTS

    //don't use '[]' for inserting elements
    //v[3] = 1002;
    //v[4] =1234;

    v.push_back(23);
    v.push_back(234);

    v.pop_back();

    //can use both: square brackets and at function
    /*
    for(int i=0;i<v.size();i++){
        cout << v.at(i) << endl;
    }
    */

    /*
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;
    
    
    cout << "Size: " << v.size() << endl;

    //AT IS MORE SAFER THAN SQUARE BRACKETS AS IT DOES PRINT GARBAGE VALUES 
    cout << v.at(2) << endl;
    cout << v.at(6) << endl;
    */
}