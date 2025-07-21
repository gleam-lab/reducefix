#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
set<int> s[MAXN];

void mergeSets(int u, int v) {
    if (s[u].size() > s[v].size()) swap(u, v);
    for (auto it : s[u]) {
        s[v].insert(it);
    }
    s[u].clear();
}

void addEdge(int u, int v) {
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    
    if (s[u].empty() && s[v].empty()) {
        s[u].insert(u + 1);
        s[v].insert(v + 1);
    } else if (!s[u].empty() && !s[v].empty()) {
        if (s[u].size() <= s[v].size())
            mergeSets(u, v);
        else
            mergeSets(v, u);
    } else {
        if (s[u].empty())
            s[u] = s[v];
        else
            s[v] = s[u];
    }
}

int getKthLargest(int u, int k) {
    u--;
    if (s[u].size() < k) return -1;
    auto it = s[u].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            addEdge(u, v);
        } else {
            cout << getKthLargest(u, v) << "\n";
        }
    }
    
    return 0;
}