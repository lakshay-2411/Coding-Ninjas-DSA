#include <iostream>
using namespace std;
int main()
{
    int k=33,a=10,b=10;
    for(int i=1;i<=30;i++)
    {
        for(int j=1;j<=40;j++)
        {
            if(i==1)
            {
                if(j>=10&&j<31)
                cout<<"*";
                else
                cout<<" ";
                
            }
            if(i>1&&i<10)
            {
                a--,b++,k++;
                if(j==a||j==b||j==k)
                cout<<"*";
                else
                cout<<" ";
                
            }
            if(i==10)
            {
                cout<<"*";
            }
            if(i>10&&i<30)
            {
                if(j==1||j==20||j==40)
                cout<<"*";
                else
                cout<<" ";
            }
            if(i==30)
            {
                cout<<"*";
            }

        }
        cout<<""<<endl;
    }
}