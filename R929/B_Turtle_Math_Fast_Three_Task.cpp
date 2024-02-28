#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int s = 0;
    int a;
    int r1 = -1;
    for (int i=0; i<n; i++) {
        cin >> a;
        s += a;
        if (a % 3 == 1) r1 = a;
    }

    int r = s % 3;
    if (r == 0) {
        cout << 0 << endl;
    } else if (r == 1) {
        if (r1 != -1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        cout << 1 << endl;
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