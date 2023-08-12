#include <iostream>
using namespace std;

int main(){

    //CONSTANT INT

    const int i = 10;   //When using const initialize the variable at the time of declaration only
/*     //Both are same
    int const i = 19;  
    const int i = 19;
*/

//    i = 12;         //we can do this if we are taking int i but can't do  this if we are taking constant i

        //the variable is not a constant, the path through which it points becomes constant








    //CONSTANT REFERENCE FROM A NON CONSTANT INT

    int j = 12;
    const int &k = j;
//    k++;        //we can not do this as we have declared its path to be constant
    j++;        //we can do this operation as it's path is not a constant
    cout << k << endl;





    //CONSTANT REFERENCE FROM A CONSTANT INT

    int const j2 = 10;
    int const &k2 = j2;
    //Now we cannot change the value of k2 or j2 through any path because both are constant




    //REFERENCE FROM A CONSTANT INT

    int const j3 = 10;
    int &k3 = j3;
    //As we can't make changes from the parent then we will not have the power to change its value through its copy
    //Therefore it's a wrong method and we should not use this

}