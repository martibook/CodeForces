#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

void solve() {
    char a[3][3];
    for(int i=0; i<3; i++) {
        for(int j=0; j< 3; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0; i<3; i++) {
        bool A=false, B=false, C=false;
        for(int j=0; j< 3; j++) {
            if(a[i][j] == 'A') A = true;
            if(a[i][j] == 'B') B = true;
            if(a[i][j] == 'C') C = true;
        }
        if(A && B && C) {
            continue;
        } else {
            char ans = !A ? 'A' : !B ? 'B' : 'C';
            cout << ans << endl;
            return;
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