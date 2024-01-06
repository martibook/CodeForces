#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*

当 1 + 2 + … + k < x 时，一定要加下去 否则永远到不了 x

假设 1 + 2 + … + k+1 > x
则需要改变之前的某个操作，使添加总和变小一点，刚好等于 x

总和大于 x 的量一定不会超过 k+1 否则不用加 k+1 都刚好了

假设 累加的和 比 x 多的部分是 d
1 <= d < k+1

那么 [1 … k] 之间一定有一个数等于 d
既然多了 d 那就要把 jump d 这个动作撤回

撤回实际只是把操作变成 -1（操作数量不增加）
实际上改变操作的是 d 左边那个数（不累加这个数，并把和-1）

为了保证 d 左边至少会有一个数字
d == 1 需要特别考虑

d == 1 没有办法通过改变之前的操作达到目的，只能添加一个单独的 -1 操作（操作数+1）
d > 1 更改 d 左边那个数的操作（操作数不变）

*/

void solve() {
    int x;
    cin >> x;

    int cnt = 0, k = 1;
    while(x > 0) {
        x -= k;
        cnt++;
        k++;
    }

    cnt += (0 - x == 1)? 1 : 0;

    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}