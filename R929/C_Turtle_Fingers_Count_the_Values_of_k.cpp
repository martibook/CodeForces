#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;

    set<int> s;
    for (int ax=1; l % ax == 0; ax *= a) {
        int ll = l / ax;
        for (int by=1; ll % by == 0; by *= b) {
            s.insert(ll / by);
        }
    }

    cout << s.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}