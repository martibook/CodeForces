#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

/*
最后只需要知道 有多少人排在 Rudolf 前面，不需要知道整个排序
所以只需要一个变量，记录 Rudolf 的最终排名
*/

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    int rank = 1;
    long long points = 0;
    long long time = 0;
    long long penalty = 0;
    int t[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
        }
        
        sort(t[i], t[i] + m);

        long long points_i = 0;
        long long time_i = 0;
        long long penalty_i = 0;

        for (int j = 0; j < m; j++)
        {
            if (time_i + t[i][j] <= h)
            {
                time_i += t[i][j];
                penalty_i += time_i;
                points_i += 1;
            }
        }
        
        if (i == 0)
        {
            points = points_i;
            penalty = penalty_i;
        }
        else
        {
            if (points_i > points || (points_i == points && penalty_i < penalty))
            {
                rank += 1;
            }
        }
    }

    cout << rank << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}