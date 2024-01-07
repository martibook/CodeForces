#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    int s=n, t=n;
    int p=0;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        int ss = min(s, t);
        int tt = max(s, t);
        s = ss;
        t = tt;
        if(x <= s) {
            s = x;
        }
        else if (x <= t)
        {
            t = x;
        }
        else {
            p++;
            s = x;
        }
    }

    cout << p << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}