/*
E
D E
C D E
B C D E
A B C D E
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(char ch = 'A' + (n - i); ch < 'A' + n; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}