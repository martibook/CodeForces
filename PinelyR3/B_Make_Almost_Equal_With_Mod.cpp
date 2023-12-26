#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

/*
一个程序员应当对 二进制 有相当程度的敏感才对

两个二进制数
10
11
只有末位不同， mod 之后不就是 exactly 2 distinctive values 吗

如果末位相同
00
10
那么 mod 的对象需要 *2, 余数就是 00 和 10，也是 exactly 2 distinctive values
*/

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    ll a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll k = 2;
    while(k < 1E18) {
        set<ll> remainders;
        for(int i=0; i<n; i++) {
            remainders.insert(a[i] % k);
            if(remainders.size() > 2)
                break;
        }
        if(remainders.size() == 2)
            break;
        else
            k *= 2;
    }

    cout << k << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}