#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
观察
1. q[i] belong to [1, n] 所以不能超过 n
2. p[1] = q[1]
3. 如果 q[i] != q[i-1], 那么 p[i] = q[i]
4. 如果 q[i] == q[i-1], 那么 p[i] 一定是一个小于 q[i] 的数字

维持一个 taken[] 记录哪些数字被使用过
从小到大在 taken[] 中寻找没有用过的数，不容易超时（相对于从大到小而言）
*/

void solve() {
    int n;
    cin >> n;

    int q[n];
    for (int i = 0; i < n; i++) cin >> q[i];
    
    bool taken[n+1];
    for (int i = 0; i <= n; i++) taken[i] = false;
    
    int p[n];
    int v = 1;
    for (int i = 0; i < n; i++)
    {
        if (q[i] > n)
        {
            cout << -1 << endl;
            return;
        }

        if (i == 0)
        {
            p[0] = q[0];
            taken[q[0]] = true;
            continue;
        }
        
        if (q[i] != q[i-1])
        {
            p[i] = q[i];
            taken[q[i]] = true;
        }
        else
        {
            while (taken[v]) v++;

            if (v < q[i])
            {
                p[i] = v;
                taken[v] = true;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }        
    }
    
    for (int i = 0; i < n; i++) cout << p[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}