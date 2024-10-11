/*
ABCDE
ABCD
ABC
AB
A
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(char ch='A'; ch<=('A'+(n-i)); ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}