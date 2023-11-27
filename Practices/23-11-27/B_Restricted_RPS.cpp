#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ar, ap, as;
    cin >> ar >> ap >> as;

    string bact;
    cin >> bact;

    int br=0, bp=0, bs=0;
    for (int i = 0; i < n; i++)
    {
        br += bact[i] == 'R'? 1 : 0;
        bp += bact[i] == 'P'? 1 : 0;
        bs += bact[i] == 'S'? 1 : 0;
    }

    int win = min(ar, bs) + min(ap, br) + min(as, bp); // 只要匹配的次数超过一半 就能赢
    bool couldWin = win >= ((n+(2-1)) / 2);

    if (!couldWin)
    {
        cout << "NO" << endl;
        return;
    }

    char aact[n];
    // 先把匹配的字母填上
    for (int i = 0; i < n; i++)
    {
        if (bact[i] == 'R')
        {
            if (ap > 0)
            {
                aact[i] = 'P';
                ap--;
            }
            else
                aact[i] = 'E';
            
        }
        else if (bact[i] == 'P')
        {
            if (as > 0)
            {
                aact[i] = 'S';
                as--;
            }
            else
                aact[i] = 'E';
        }
        else // bact[i] == 'S'
        {
            if (ar > 0)
            {
                aact[i] = 'R';
                ar--;
            }
            else
                aact[i] = 'E';
        }
    }

    // 再把多余的字母填上
    for (int i = 0; i < n; i++)
    {
        if (aact[i] == 'E')
        {
            if (ar > 0)
            {
                aact[i] = 'R';
                ar--;
            }
            else if (ap > 0)
            {
                aact[i] = 'P';
                ap--;
            }
            else
            {
                aact[i] = 'S';
                as--;
            }
        }
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << aact[i];
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