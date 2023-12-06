#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

int N = 26;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c[N];
    int m=0;
    for (int i=0; i<N; i++) c[i]=0;
    for (int i=0; i<n; i++) {
        c[s[i]-'a']++;
        if (c[s[i]-'a'] > m) m = c[s[i]-'a'];
    }

    if (m <= (n+1)/2) cout << n % 2 << endl;
    else cout << m - (n - m) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}