#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
这个操作只会把数变小

一个数 操作于 任意数(>1) 都会变小
但操作于 1， 不会变小，所以 1 特殊

若数组中有 1， 也有其他数，1 无法变成其他数，其他数只能 操作于 1 时也无法变成 1

判断全部数是否相等：max == min?

过程：把数列中的 max 不断变小
max/min 选用常见的特殊值

max/其他值  可能会下降太快 错过变成 min 的机会 也许最终的变换就不成功
比如 9 3 9
如果 9/9 则直接失败
*/


void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int im = max_element(a, a+n) - a, in = min_element(a, a+n) - a;
    if (a[in] == 1 && a[im] != a[in])
    {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    int op[30*n+1][2];
    while (a[im] != a[in])
    {
        a[im] = (a[im] + a[in] - 1) / a[in];
        op[cnt][0] = im;
        op[cnt][1] = in;
        ++cnt;
        im = max_element(a, a+n) - a;
        in = min_element(a, a+n) - a;
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << op[i][0] + 1 << " " << op[i][1] + 1 << endl;
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