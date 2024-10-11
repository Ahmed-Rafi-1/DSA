/*
*      *
**    **
***  ***
********
***  ***
**    **
*      *
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int space1 = 2*n-2;
    for(int i=1; i<=n; i++)
    {
        //for star
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        //for space
        for(int j=1; j<=space1; j++)
        {
            cout << " ";
        }
        //for star
        for(int j=1; j<=i; j++)
        {
            cout << "*";
        }
        cout << endl;
        space1 -= 2;
    }
    int space2 = 2;
    for(int i=1; i<=n-1; i++)
    {
        //for star
        for(int j=1; j<=n-i; j++)
        {
            cout << "*";
        }
        //for space
        for(int j=1; j<= space2; j++)
        {
            cout << " ";
        }
        //for stars
        for(int j=1; j<=n-i; j++)
        {
            cout << "*";
        }
        cout << endl;
        space2 += 2;
    }
}