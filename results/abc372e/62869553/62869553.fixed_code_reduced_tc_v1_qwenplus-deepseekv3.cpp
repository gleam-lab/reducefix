#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<priority_queue<int, vector<int>, greater<int>>> top10(MAXN); // Min-heap to keep top 10 largest

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    
    if (top10[u].size() < top10[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    
    while (!top10[v].empty()) {
        int val = top10[v].top();
        top10[v].pop();
        top10[u].push(val);
        if (top10[u].size() > 10) {
            top10[u].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top10[i].push(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (top10[root].size() < v) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                while (top10[root].size() > v) {
                    temp.push_back(top10[root].top());
                    top10[root].pop();
                }
                int ans = top10[root].top();
                cout << ans << "\n";
                for (int x : temp) {
                    top10[root].push(x);
                }
            }
        }
    }
    
    return 0;
}