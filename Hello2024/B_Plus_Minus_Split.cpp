#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    char c;
    int p=0, m=0;
    for(int i=0; i<n; i++) {
        cin >> c;
        if(c == '+') p++;
        if(c == '-') m++;
    }

    int ans = max(p, m) - min(p, m);
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