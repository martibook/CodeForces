#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int b=0, B=0;
    for (int i=s.length()-1; i>=0; i--) {
        if (s[i] == 'b') {
            b++;
            s[i]='\0';
        } else if (s[i] == 'B') {
            B++;
            s[i]='\0';   
        } else {
            if (islower(s[i]) && b>0) {
                b--;
                s[i]='\0';
            }
            if (isupper(s[i]) && B>0) {
                B--;
                s[i]='\0';
            }
        }
    }
    
    for (int i=0; i<s.length(); i++) {
        if (s[i] != '\0') cout << s[i];
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