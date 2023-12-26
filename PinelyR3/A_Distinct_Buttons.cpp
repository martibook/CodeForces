#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack> 
using namespace std;

void solve() {
    int n;
    cin >> n;

    bool up=false, down=false, left=false, right=false;

    int x, y;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        if(x>0) right=true;
        if(x<0) left=true;
        if(y>0) up=true;
        if(y<0) down=true;
    }

    if(!up || !down || !right || !left) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}