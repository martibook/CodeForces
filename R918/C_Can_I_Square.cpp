#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
#include<cmath>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    ll x;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> x;
        sum += x;
    }

    double root = sqrt(sum);
    string ans = (root == floor(root)) ? "YES" : "NO";

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