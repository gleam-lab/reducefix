#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<priority_queue<int>> max_heaps;

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (max_heaps[u].size() < max_heaps[v].size()) {
        swap(u, v);
    }
    while (!max_heaps[v].empty()) {
        max_heaps[u].push(max_heaps[v].top());
        max_heaps[v].pop();
    }
    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    parent.resize(N + 1);
    max_heaps.resize(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        max_heaps[i].push(i);
    }
    
    while (Q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            union_sets(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = find(v);
            if (max_heaps[v].size() < k) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                for (int i = 0; i < k; ++i) {
                    temp.push_back(max_heaps[v].top());
                    max_heaps[v].pop();
                }
                cout << temp.back() << '\n';
                for (int num : temp) {
                    max_heaps[v].push(num);
                }
            }
        }
    }
    
    return 0;
}