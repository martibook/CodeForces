#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

bool V(char c) {
    return c == 'a' || c == 'e';
}

bool C(char c) {
    return c == 'b' || c == 'c' || c == 'd';
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> sy;
    int i = n - 1;
    while(i > 0) {
        if(V(s[i])) {
            sy.push_back(s.substr(i-1, 2));
            i -= 2;
        } else {
            // s[i] == 'C'
            sy.push_back(s.substr(i-2, 3));
            i -= 3;
        }
    }

    for(int i=sy.size()-1; i>=0; --i) {
        cout << sy[i];
        if(i>0) cout << ".";
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