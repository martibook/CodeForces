#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int a, b;
    cin >> a >> b;

    string winner = (a+b) % 2 == 1 ? "Alice" : "Bob";
    cout << winner << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}