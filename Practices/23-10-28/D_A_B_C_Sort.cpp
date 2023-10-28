#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
关键思考：从 a -> b，从 a1 开始拿取，依次往 b 的左右两边摆放，和题面效果相同
关键思考：因为要保持对称，放第一个元素时可选左右，放第二个元素只有一种选择
可以认为，元素总是两个两个一起放

关键思考 结合 题面 b -> c 的过程，可得
a -> b -> c 的过程简化为：从 a 直接按顺序搬到 c
若 n 为奇数，c[0] = a[0]
此后，a[i], a[i+1] 总是被一起放到 c, 只有 (a[i], a[i+1]) 之间的顺序可以调整
所以只要比较 (a[i], a[i+1]) 与 下一对 (a[i], a[i+1]) 的最值是否满足要求 
*/

void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int last = 0;
    if (n % 2 == 1)
    {
        last = a[0];
        for (int i = 0; i < n / 2; i++)
        {
            if (last > min(a[2*i+1], a[2*i+2]))
            {
                cout << "NO" << endl;
                return;
            }
            last = max(a[2*i+1], a[2*i+2]);
        }
    }
    else
    {
        for (int i = 0; i < n/2; i++)
        {
            if (last > min(a[2*i], a[2*i+1]))
            {
                cout << "NO" << endl;
                return;
            }
            last = max(a[2*i], a[2*i+1]);
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