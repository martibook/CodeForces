#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<stack>
using namespace std;

typedef long long ll;

const int N=200005;
vector<int> e[N]; // 在 solve 中声明的话 由于每轮都是用新的内存 会超
bool v[N];
ll c[N];

void solve() {
    int n;
    cin >> n;

    for (int i=0; i<n+1; i++) {
        e[i].clear(); // edges of node i
        v[i] = false; // visited node i
        c[i] = 0; // cnt of leaf nodes of node i
    }

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    // 一开始以外 dfs 导致了 stack overflow, 其实是内存使用超了
    // 使用 dfs(current node, parent node) 代码会更简洁, node 1's parent could be -1 (parent node 的用意是不要往回搜索)
    stack<int> nodes; 
    nodes.push(1);
    v[1] = true;
    while (!nodes.empty()) {
        int p = nodes.top();

        if (e[p].size() == 1 && p != 1) {
            c[p] = 1;
            nodes.pop();
            continue;
        }

        bool childNotReady = false;
        for (auto ch : e[p]) {
            if (!v[ch]) {
                nodes.push(ch);
                v[ch] = true;
                childNotReady = true;
            }
        }

        if (!childNotReady) {
            for (auto ch : e[p]) {
                c[p] += c[ch];
            }
            nodes.pop();
        }
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        cout << c[x] * c[y] << endl;
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