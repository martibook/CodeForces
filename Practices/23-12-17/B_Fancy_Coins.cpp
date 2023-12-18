#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack> 
using namespace std;

/*

a1, ak: available cnt of 1, k
ck: needed (at most) cnt of k
fk: fancy cnt of k used
r1: the rest available cnt of 1

*/

void solve() {
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    int ck = m / k; // the most amount of coin k that's needed.
    int klow = min(ak, ck);
    int khigh = max(klow, ck); // anyway no more than ck.

    while (klow < khigh)
    {
        int kmid = (klow + khigh + 1) / 2; // 中点偏左/右 取决于调整动作，右边有下调渠道，中点就可以偏右，这样能保证循环会结束
        int r1 = a1 - (m - kmid * k);
        if (r1 >= k) {
            // you've used too much fancy k, coz you could have paid with the remaining coin 1.
            // 我能明确地知道这个 coin 不该使用，所以这是一个合适的判断条件
            khigh = kmid - 1; // 这也是一个合适的调整动作
        } else {
            klow = kmid;
        }
    }

    int fk = max(klow - ak, 0);
    int f1 = max(m - klow * k - a1, 0);

    cout << fk + f1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}