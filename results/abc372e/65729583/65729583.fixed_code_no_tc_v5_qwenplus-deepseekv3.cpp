#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int parent[N];
priority_queue<int> heaps[N];

int Find(int u) {
    if (parent[u] != u) {
        parent[u] = Find(parent[u]);
    }
    return parent[u];
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    
    // Always merge smaller heap into larger one
    if (heaps[u].size() < heaps[v].size()) {
        swap(u, v);
    }
    
    parent[v] = u;
    
    // Merge heaps, keeping only top 10 elements
    while (!heaps[v].empty()) {
        heaps[u].push(heaps[v].top());
        heaps[v].pop();
        if (heaps[u].size() > 10) {
            heaps[u].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    // Initialize DSU and heaps
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        heaps[i].push(i);  // Each node initially has itself
    }
    
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            
            if (heaps[v].size() < k) {
                cout << -1 << '\n';
            } else {
                // Temporary storage to get k-th largest
                vector<int> temp;
                while (!heaps[v].empty()) {
                    temp.push_back(heaps[v].top());
                    heaps[v].pop();
                }
                
                int res = temp[k-1];
                cout << res << '\n';
                
                // Restore the heap
                for (int num : temp) {
                    heaps[v].push(num);
                }
            }
        }
    }
    
    return 0;
}