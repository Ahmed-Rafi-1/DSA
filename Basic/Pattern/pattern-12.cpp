/*
    1      1
    12    21
    123  321
    12344321
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        //for num
        for(int j=1; j<=i; j++)
        {
            cout << j;
        }
        //for space
        int space = (2*n)-(2*i);
        for(int j=1; j<=space; j++)
        {
            cout << " ";
        }
        //for num
        for(int j=i; j>=1; j--)
        {
            cout << j ;
        }
        cout << endl;
       
    }
}