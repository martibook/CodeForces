#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack>
using namespace std;

const int N=101;
int l[N]; // there're l[i] people said there were AT LEAST i liars in the group.
int s[N]; // s[i]: sum of l[1] ... l[i]

void solve() {
    int n;
    cin >> n;

    for(int i=0; i<N; i++) {
        l[i] = 0;
        s[i] = 0;
    }

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        l[x]++;
    }

    s[0] = l[0];
    for(int i=1; i<=n; i++) {
        s[i] = s[i-1] + l[i];
    }

    for(int i=0; i<=n; i++) {
        // if there were i liars, s[i] people are telling the truth, actual liars are n - s[i]
        if(n - s[i] == i) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}