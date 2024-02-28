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
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a >= 0) s += a;
        else s += -a;
    }
    
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}