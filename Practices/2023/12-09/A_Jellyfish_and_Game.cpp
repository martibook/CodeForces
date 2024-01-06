#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack> 
using namespace std;

typedef long long ll;

/*
每一轮操作的目的是，保证拿到全局最大值，丢掉全局最小值
所以需要维护 ming(global), maxg

k=1, J 需要保证这个目的，但不一定会换，因为有可能 J 的所有值都大于 G 的所有值
如果 J 要换的话，只能是因为 maxb > mina

第一轮之后
maxg 一定在 J，ming 一定在对面

从 k=2 开始，双方的目的每一轮都是拿到对面的 maxg, 把自己的 ming 丢给对方
所以只要看 (k-1) 是奇数还是偶数
奇数，G 就还有机会占上风
偶数，J 保持第一轮之后的上风
*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ll mina = LLONG_MAX, maxa = LLONG_MIN;
    ll minb = LLONG_MAX, maxb = LLONG_MIN;
    ll ming = LLONG_MAX, maxg = LLONG_MIN;
    ll sj = 0, sg = 0;

    ll a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sj += a[i];
        if(a[i] < mina) mina = a[i];
        if(mina < ming) ming = mina;
        if(a[i] > maxa) maxa = a[i];
        if(maxa > maxg) maxg = maxa;
    }

    ll b[m];
    for(int i=0; i<m; i++) {
        cin >> b[i];
        sg += b[i];
        if(b[i] < minb) minb = b[i];
        if(minb < ming) ming = minb;
        if(b[i] > maxb) maxb = b[i];
        if(maxb > maxg) maxg = maxb;
    }

    // k == 1, J would make sure to get global max, and dump global min
    ll swap = max(maxb - mina, (ll)0);
    sj += swap;
    sg -= swap;

    // after the first round, J would definitely get the global max, and dump the global min
    // from k=2,.. J and G would both make sure to get global max and dump global min, when it's their turn
    if((k-1) % 2 == 1) {
        ll swap = maxg - ming;
        sj -= swap;
        sg += swap;
    }

    cout << sj << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}