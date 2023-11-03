#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;


void solve() {
    int n;
    double d, h;
    cin >> n >> d >> h;

    double s_triangle = 0.5L * d * h;
    double h_pow = 1.0L * h * h;

    double y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }

    double s = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long hi = h - (y[i+1] - y[i]);
        if (hi > 0)
        {
            s += s_triangle * hi * hi / h_pow;
        }
    }

    cout << fixed << setprecision(10) << s_triangle * n - s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}