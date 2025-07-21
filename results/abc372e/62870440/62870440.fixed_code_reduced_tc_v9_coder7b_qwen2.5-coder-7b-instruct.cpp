#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
vector<int> adj[MAXN];
set<int> s[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    s[u].insert(v);
    s[v].insert(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            if (s[v].size() < k) cout << "-1\n";
            else {
                auto it = s[v].rbegin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}