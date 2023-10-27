#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
观察：所有元素取值 [0, m-1]

定义：中间结果行

目的：max s
过程：若中间结果行能连续占满 [0 -> 某个数]，则 s = 某个数 + 1， 取得最大值
中间结果行的某个位置 若想占掉 某个值，则这个位置 对应的原始列 就要缺少这个值 并占满 [0 -> 这个值 - 1]
让每一列都刚刚缺少 某个值，这通过得当的安排来实现
一列中有 n 个数，如果一列中能刚好缺少 m 个数值中的某一个，那么一列中最多只能有 (m-1) 个不同的数字，这只需要 m-1 行就能做到
所以 n 足够大的时候，每 (m-1) 行开始一个循环

(i%(m-1) + j) % m

s = min(n+1, m) 因为中间结果行的存在，n+1 才是限制（相当于多了一行）
m 为什么是限制？因为中间结果行顶多只有 m 的位置，最理想情况占满 [0 -> m-1]，则 s=m 最优
n+1 为什么是限制？当 n 明显比 m 小时，原始列只能占满 [0, n-1] 这些数值，加上中间结果行，也只能占满 [0 -> n] 这些数值，则 s=n+1 最优
*/

void solve() {
    int n, m;
    cin >> n >> m;

    if (m == 1)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 0 << endl;
        }
        return;
    }

    cout << min(n + 1, m) << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j < m - 1)
            {
                cout << (i % (m-1) + j) % m << " ";
            }
            else
            {
                cout << (i % (m-1) + j) % m << endl;
            }
        }        
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