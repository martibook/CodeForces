#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
n 个点 最多不能超过 n(n-1)/2 条边，因为这样已经是每两个点都有一条边了
n 个点 最少需要 n-1 条边，除了一个中点以外其他点都需要一条边让它加入这个图

注意 < k - 1

k<=1 impossible
d<=0 (k==2) n==1
d<=1 (k==3) 所有点都有边直接相连 m==n(n-1)/2
k>3 只要 n-1 <= m <= n(n-1)/2 准能排列得满足条件

想的没有错 没有遗漏
就是 int overflow 了
*/

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    // No self-loop
    if (m > n * (n - 1) / 2)
    {
        cout << "NO" << endl;
        return;
    }

    if (k <= 1)
    {
        cout << "NO" << endl;
        return;
    }
    else if (k == 2 && n != 1)
    {
        cout << "NO" << endl;
        return;
    }
    else if (k == 3 && m < n * (n - 1) / 2)
    {
        cout << "NO" << endl;
        return;
    }
    else 
    {
        if (m < n - 1)
        {
            cout << "NO" << endl;
            return;
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