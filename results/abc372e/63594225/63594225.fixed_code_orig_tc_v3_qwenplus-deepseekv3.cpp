#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<priority_queue<int>> components;

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
    
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    
    priority_queue<int> temp;
    while (!components[v].empty()) {
        temp.push(components[v].top());
        components[v].pop();
    }
    
    while (!temp.empty()) {
        components[u].push(temp.top());
        temp.pop();
        if (components[u].size() > 10) {
            components[u].pop();
        }
    }
    
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    parent.resize(N+1);
    components.resize(N+1);
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        components[i].push(i);
    }
    
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        
        if (t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (components[root].size() < v) {
                cout << "-1\n";
            } else {
                priority_queue<int> temp = components[root];
                for (int i = 0; i < v-1; i++) {
                    temp.pop();
                }
                cout << temp.top() << '\n';
            }
        }
    }
    
    return 0;
}