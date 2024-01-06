#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
首先 a <-> b 可以直接 可以间接

a b ... c
a <-> c
c b ... a
b <-> a
c a ... b
c <-> b
b a ... c
通过引入 c, a b 完成交换

设置可以引入 c d, 帮助 a b 完成交换
c .. a b .. d
c <-> b, a <-> d
b .. d c .. a
a <-> b
a .. d c .. b
a <-> c, d <-> b
c .. b a .. d


如果 a[i] 在排序后的数组中需要变换位置
要满足 max(i, n-i-1) >= x 
a[i] 需要有一个距离它足够远的数 可以帮助它 交换位置

因为我们可以引入不止一个帮助角色
所以如果 a[i] 需要与 a[j] 交换
a[i] 的帮助角色 与 a[j] 的帮助角色 可以不是同一个
通常来说 帮助角色都是最远端的数
所以即便不是同一个帮助角色 它们本身也相距够远
*/

void solve() {
    int n, x;
    cin >> n >> x;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            if (max(i, n - i - 1) < x)
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