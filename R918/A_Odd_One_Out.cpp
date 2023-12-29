#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b) {
        cout << c << endl;
        return;
    }

    int ans = b == c ? a : b;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}