#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    }

    for (int i = 0; i < n; i++)
        sort(b[i], b[i] + m); // every line non-descending

    for (int j = m; j > 0; j--)
    {
        int mi = 0;
        for (int i = 0; i < n; i++)
            if (b[i][0] < b[mi][0]) mi = i;
        // comparing elements in the first column, now the smallest one comes from mi-th line
        // take 0-th element on mi-th line to the end of the line
        rotate(b[mi], b[mi]+1, b[mi]+j);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}