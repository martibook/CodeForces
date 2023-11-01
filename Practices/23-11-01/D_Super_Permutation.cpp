#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
观察: a, b 都是 permutation, 每个数只能出现一次

n 的奇偶性是否有影响？
1 + ... + n 求和公式
n 为奇数， b[n] = 0，那么 b 中不能再出现 0，因为 n % n 与 0 关系密切，考虑 n 的位置
- 开头，b[0] = b[n] = 0
- 中间，b[i-1] = b[i]
- 末尾，b[n-1] = b[n] = 0
故 n 为奇数 -> 无解

n 为偶数
寻找 a b 之间的联系
先看一个最简单的例子
a 为 [1 2 3 4], [4 3 2 1] 时，过程中可以发现

b[i+1] = b[i] + x,  a[i] = x
b[i+1] = b[i] - x,  a[i] = n - x

上升时，x = a[i]
下降时，x = n - a[i]

a[i] 不能重复，且 [1 -> n] 每个数得出现一次
一个好办法（构造的部分）是把 a[i] 分为 奇数 偶数，注意构造不是要排除其他的可能性，只是提出一种可能，这道题本来不止一种解法
这样做的结果是 x 也不会重复了，而且 [0 -> n-1] 每个数都会出现一次


现在，根据已知重新整理一下约束条件
b 是一个不能重复的数列，取值在 [0, n-1] 之间
b 的相邻差值是一个不能重复的数列，取值在 [0, n-1] 之间

比如 n = 6 时
如果画出数轴，x轴 y轴 都标上 0->6 的刻度，(0,0) (1,5) (2,1) (3,4) (4,2) (5,3) 仿佛一个振荡收拢的图像

db: |delta b|
b[0] = 0,  db = 6(假设从6突然将为1), a[0] = n - db = 6（下降)
b[1] = 5,  db = 5,  a[1] = 5
b[2] = 1,  db = 4,  a[2] = 2
b[3] = 4,  db = 3,  a[3] = 3
b[4] = 2,  db = 2,  a[4] = 4
a[5] = 3,  db = 1,  a[5] = 1

a[0] = 6, n-i
a[1] = 5, n-i
a[2] = 2, i
a[3] = 3, n-i
a[4] = 4, i
a[5] = 1, n-i
*/

void solve() {

    int n;
    cin >> n;
    if (n >1 && n % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i==0)
        {
            cout << n;
        }
        else if (i % 2 == 1)
        {
            cout << n - i;
        }
        else
        {
            cout << i;
        }

        if (i < n-1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
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