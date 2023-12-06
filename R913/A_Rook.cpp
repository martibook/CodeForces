#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

void solve() {
    string pos;
    cin >> pos;

    char col=pos[0], row=pos[1];
    for (char c='a'; c<='h'; c++)
    {
        if (c != col) {
            cout << c << row << endl;
        }
    }
    for (char r='1'; r<='8'; r++)
    {
        if (r != row)
        {
            cout << col << r << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}