#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
依次找到 a[n] 最大的数，
a[i] mod a[i] -> 0
a[i] mod a[i]-1 -> 1

if a[i] >= 3, -> 0 or -> 1
if a[i] == 2, -> 0
if a[i] == 1, -> 1
if a[i] == 0, -> 0

所以 1 不能与 0 or 2 共存

若 1 存在，a[i] a[i+1] 相距不能为 1
否则在把 a[i+1](greater one) 变成 1 的过程，就把 a[i] 变成 0 了
*/

void solve() {
    int n;
    cin >> n;
    
    int a[n];
    bool e1 = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            e1 = true;
        }
    }

    if (e1)
    {
        sort(a, a + n);
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i+1] - a[i] == 1)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}