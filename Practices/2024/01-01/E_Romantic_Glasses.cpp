#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
s[i]: sum of i elements, [a[1], a[i]]
c[i][j]: s[j] - s[i]

a[1] ... a[n]
make all even(start from 1) elements negative of themselves
goal: c[][] == 0 and i != j

如果直接去计算 c[][] 需要二维循环 可能超时
根据条件如果 c[i][j] == 0 则有 s[i] == s[j]
可以在一维遍历 到达 j 时检查之前有没有 s[i] == s[j] (via map)

*/

void solve() {
    int n;
    cin >> n;

    ll a, s = 0;
    bool possible = false;
    map<ll, int> m; // prev sum
    for(int i=0; i<n; i++) {
        cin >> a;
        if(i % 2 == 1) {
            a = -1 * a;
        }
        s += a;
        possible |= s == 0 || m[s];
        m[s]++;
    }

    string ans = possible ? "YES" : "NO";
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