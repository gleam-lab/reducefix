#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;
const int MAX_K = 10;

int parent[MAX_N];
vector<int> component[MAX_N];
priority_queue<int, vector<int>, greater<int>> top_k[MAX_N];

int find_set(int u) {
    if (parent[u] != u) {
        parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) return;
    
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    
    // Merge the smaller component into the larger one
    parent[v] = u;
    
    // Merge the top k elements
    for (auto x : component[v]) {
        if (top_k[u].size() < MAX_K) {
            top_k[u].push(x);
        } else if (x > top_k[u].top()) {
            top_k[u].pop();
            top_k[u].push(x);
        }
    }
    
    // Merge the component lists
    component[u].insert(component[u].end(), component[v].begin(), component[v].end());
    component[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        component[i].push_back(i);
        top_k[i].push(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u;
        
        if (op == 1) {
            cin >> v;
            merge(u, v);
        } else {
            int k;
            cin >> k;
            u = find_set(u);
            
            if (top_k[u].size() < k) {
                cout << "-1\n";
                continue;
            }
            
            vector<int> temp;
            while (!top_k[u].empty()) {
                temp.push_back(top_k[u].top());
                top_k[u].pop();
            }
            
            cout << temp[temp.size() - k] << "\n";
            
            for (auto x : temp) {
                top_k[u].push(x);
            }
        }
    }
    
    return 0;
}