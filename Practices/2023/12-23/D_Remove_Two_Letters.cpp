#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack> 
using namespace std;

/*
一个 rm string 与下一个 rm string 
正着相同
或
反着相同
都会造成 remove 之后留下的 string 内容相同
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string rm = s.substr(0, 2);
    int r = 0;
    for(int i=1; i<n-1; i++) {
        string rm2 = s.substr(i, 2);
        if( (rm[0]==rm2[0] && rm[1]==rm2[1]) || (rm[0]==rm2[1] && rm[1]==rm2[0]) ) {
            r++;
        } else {
            rm = rm2;
        }
    }

    cout << n-1 - r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}