#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
注意 int overflow !

non-descending 以及 a[x] = a[y] - a[z]
但凡 a[z] >= 0  a[x] < a[y] 就一定成立

所以当出现 a[i]>a[i+1] 时， i+1 的右侧必须有个 a[z]>=0 才能把 a[i] 变得符合题意

题目没有要求 operation 次数是可能解法中最少的
只要次数不超过 n 即可
那么只要每次都使用整个数列最右侧的 a[z] 即可（因为不用把 a[i] 改造得太贴切，有时候多砍一点导致左边的数原来不用被砍现在也要被砍 都是可以的）

*/


void solve() {
    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int z = -1;
    for (int i = n - 1; i >= 2; i--)
    {
        if (a[i] >= 0)
        {
            z = i;
            break;
        }
    }

    int cnt = 0;
    string ops[n];
    for (int y = n-1; y > 0; y--)
    {
        if (a[y-1] > a[y])
        {
            if (z == -1 || z <= y)
            {
                cout << -1 << endl;
                return;
            }

            a[y-1] = a[y] - a[z];
            ops[cnt++] = to_string(y) + " " + to_string(y+1) + " " + to_string(z+1);
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << ops[i] << endl;
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