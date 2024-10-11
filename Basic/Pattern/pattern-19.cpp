/*
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int spaces = 0;
    for(int i=1; i<=n; i++)
    {
        //for stars
        for(int j=1; j<=(n-i+1); j++)
        {
            cout << "*";
        }
        //for spaces
        for(int j=1; j<=spaces; j++)
        {
            cout << " ";
        }
        for(int j=1; j<=(n-i+1); j++)
        {
            cout << "*";
        }
        cout << endl;
        spaces+=2;
    }
    int spaces2 = 2*n-2;
    for(int i=1; i<=n; i++)
    {
        //for star
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        //for spaces
        for(int j=1; j<=spaces2; j++)
        {
            cout << " ";
        }
        //for star
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        cout << endl;
        spaces2-=2;
    }
}