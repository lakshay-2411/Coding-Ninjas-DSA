#include <iostream>
#include <cmath>
using namespace std;

float gp(int k){
    if(k==0){
        return 1;
    }
    float ans = gp(k-1);
    return ans + 1/(pow(2,k));
}

        /// METHOD 2 ///
        /*
float gp(int k){
    if(k==0){
        return 1;
    }
    float smallAns = (1/(pow(2,k)));
    return gp(k-1) + smallAns;
}
*/

int main(){
    int k;
    cout << "Enter the value of k " << endl;
    cin >> k;
    cout << gp(k);
}