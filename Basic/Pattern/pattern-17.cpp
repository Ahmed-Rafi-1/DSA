/*
     A
    ABA
   ABCBA
  ABCDCBA
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        //for space 
        for(int j=1; j<=n-i; j++)
        {
            cout << " ";
        }
        //for character
        char ch = 'A';
        int breakpoint = (2*i+1) / 2;
        for(int j=1; j<=(2*i-1); j++)
        {
            cout << ch;
            if(j < breakpoint)
                ch++;
            else   
                ch--;
        }
        cout << endl;
    }
}