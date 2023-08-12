#include <iostream>
using namespace std;

int main(){
    int m,n;
    cin >> m >> n;

    int ** p = new int* [m];
    for(int i=0; i<m; i++){
        p[i] = new int[n];
        for(int j=0; j<n;j++){
            cin >> p[i][j];
        }
    }

    //for deleting

    for(int i=0; i<m; i++){
        delete [] p[i];
    }
    delete [] p;    //doing this later because if we'll delete it first then p is pointing towards the arrays
                    //will remain as it is so we have to firstly delete those arrays and then p






    // for a stair like structure of 2D arrays
    //p[i] = new int[i + 1];


}