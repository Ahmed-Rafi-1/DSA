/*
    *
    **
    ***
    ****
    ***
    **
    *
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n-i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    /*
    //2nd Way
    for(int i=1; i<=2*n-1; i++)
    {
        int stars = i;
        if(i>n)
            stars = 2*n-i;
        for(int j=1; j<=stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    */
}