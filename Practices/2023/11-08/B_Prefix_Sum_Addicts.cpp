#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
由 s[n-k+1] ... s[n] 可以确定 a[n-k+2] ... a[n] 这 k -1 个数

首先 a[n-k+2] ... a[n] 要满足非递减！

1.所以前 n - k + 1 个数的和其实就是 s[n-k+1]
2.他们是非递减数列
3.他们不能超过 a[n-k+2]

设
cnt 个数的和 = s_cap (s1)
cnt 个数都不超过 a_cap (s2 - s1)
cnt (n - k + 1)

只要满足 ceil(s_cap/cnt) <= a_cap 即可，因为可以全部相等

上述过程需要 (s2 - s1) 所以 k == 1 （只有一个 s）单独判断
*/

void solve() {
    int n, k;
    cin >> n >> k;

    int s[k];
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }

    if (k == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    int a = s[1] - s[0];
    for (int i = 1; i < k-1; i++)
    {
        if (s[i+1] - s[i] < a)
        {
            cout << "No" << endl;
            return;
        }
        a = s[i+1] - s[i];
    }
    

    int scap = s[0];
    int cnt = n - k + 1;
    int acap = s[1] - s[0];

    int ave = scap > 0 ? (scap + cnt - 1) / cnt : scap / cnt;
    cout << ((ave <= acap) ? "Yes" : "No") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}