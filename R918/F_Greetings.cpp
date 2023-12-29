#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
greeting 条件
range 1 完全包含 range 2, 那么可以 greet

排序是容易想到的
pair<start, end> 按照 start 排序之后
vector<end> 按照 end 排序

遍历 pair list
使用 pair.end 在 end list 中寻找 end point 在我之前的
(此时 end list 中的 end point 对应的 start point 都比我大，只要 end 也比我小的，就能被我完全包含，我们就能 greet)

计算完后，我的 end point 应该从 end list 移除，因为所有能和我 greet 的 range 都被计算过了
*/

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> ra(n);
    vector<int> ends(n);
    for(int i=0; i<n; i++) {
        cin >> ra[i].first >> ra[i].second;
        ends[i] = ra[i].second;
    }

    sort(ra.begin(), ra.end());
    sort(ends.begin(), ends.end());

    ll g = 0;
    for(int i=0; i<n; i++) {
        int contained = lower_bound(ends.begin(), ends.end(), ra[i].second) - ends.begin();
        g += contained;
        ends.erase(ends.begin() + contained, ends.begin() + contained + 1);
    }

    cout << g << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}