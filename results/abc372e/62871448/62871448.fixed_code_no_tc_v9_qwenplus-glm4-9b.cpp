#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<int> order;
int parent[200005], size[200005];

void dfs(int v, int p) {
    parent[v] = p;
    size[v] = 1;
    for (int to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
        size[v] += size[to];
    }
    order.push_back(v);
}

int find(int v) {
    if (parent[v] == v) return v;
    parent[v] = find(parent[v]);
    return parent[v];
}

int main() {
    int N, Q;
    cin >> N >> Q;
    
    // Union-Find setup for kth largest queries
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < Q; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) { // Union query
            u--; v--;
            int root_u = find(u);
            int root_v = find(v);
            if (root_u != root_v) {
                // Attach smaller tree under larger tree
                if (size[root_u] < size[root_v]) {
                    swap(root_u, root_v);
                }
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            }
        } else if (op == 2) { // Find k-th largest query
            u--; // Adjust index to be zero-based
            int root_v = find(u);
            int k = v;
            if (k > size[root_v]) {
                cout << -1 << endl;
            } else {
                // Finding the k-th largest element
                // We do this by finding the (size[root_v] - k + 1)-th smallest element in the subtree rooted at u
                for (int x : adj[root_v]) {
                    if (parent[x] != root_v) {
                        dfs(x, root_v); // Re-root the subtree
                        sort(order.begin(), order.end(), [](int a, int b) {
                            return adj[a].size() > adj[b].size();
                        });
                        if (k <= adj[order[0]].size()) {
                            cout << order[0] + 1 << endl; // Convert index back to one-based
                            break;
                        }
                        k -= adj[order[0]].size();
                        order.clear();
                    }
                }
            }
        }
    }
    
    return 0;
}