#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

/*
想象一条一上一下的折线，容易明白
n(偶数)最多有 n/2 -1 个 local max/min，对称 
n(奇数)最多有 n/2 个 local max/min, 但不对称

local max 与 local min 个数之间最多差一
因为折线最是有上才有下 或有下才有上


*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if(max(a, b) - min(a, b) > 1) {
        cout << -1 << endl;
        return;
    }
    if(a+b > n-2) {
        cout << -1 << endl;
        return;
    }
    if(max(a, b) > n/2 - 1 + (n % 2)) {
        cout << -1 << endl;
        return;
    }

    if(max(a, b) == a) {
        // start from n - a, end with 1, go upward first, we'll have a local max, every number between [n-a+1, n] would be a local max.
        int next = n - a;
        int above = n - a + 1;
        int below = n - a - 1;
        bool up = a > b ? true : false; // if a == b, should go down first.
        while (next >= 1)
        {
            cout << next << " ";
            if(up) {
                next = above++;
                up = false;
            } else {
                next = below--;
                if(above <= n) {
                    up = true;
                }
            }
        }
        cout << endl;
        return;
    }

    // start from 1 + b, end with n, go downward first, we'll have exactly b local min, and every number between [1, b] would be a local min.
    int next = 1 + b;
    int above = 1 + b + 1;
    int below = b;
    bool down = true;
    while(next <= n) {
        cout << next << " ";
        if(down) {
            next = below--;
            down = false;
        } else {
            next = above++;
            if(below >= 1) {
                down = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}