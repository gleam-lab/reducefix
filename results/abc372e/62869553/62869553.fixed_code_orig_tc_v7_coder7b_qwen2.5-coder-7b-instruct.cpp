#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN), size(MAXN);

void init(int n) {
    iota(parent.begin(), parent.end(), 0);
    fill(size.begin(), size.end(), 1);
}

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
    if (size[u] > size[v]) swap(u, v);
    parent[u] = v;
    size[v] += size[u];
}

vector<int> getConnectedComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> components(n + 1);
    for (auto& e : edges) {
        components[find(e[0])].push_back(e[1]);
        components[find(e[1])].push_back(e[0]);
    }
    return components;
}

vector<int> solveQueries(int n, vector<vector<int>>& edges, vector<pair<int, pair<int, int>>>& queries) {
    init(n);
    vector<vector<int>> result;
    for (auto& query : queries) {
        int type = query.first;
        int v = query.second.first;
        int k = query.second.second;
        
        if (type == 1) {
            int u = query.second.first;
            int v = query.second.second;
            unite(u, v);
        } else if (type == 2) {
            vector<int> component;
            int root = find(v);
            for (int i = 1; i <= n; ++i) {
                if (find(i) == root && i != v) {
                    component.push_back(i);
                }
            }
            if (component.size() < k) {
                result.push_back(-1);
            } else {
                nth_element(component.begin(), component.begin() + k - 1, component.end());
                result.push_back(component[k - 1]);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> edges;
    vector<pair<int, pair<int, int>>> queries;
    
    for (int i = 0; i < q; ++i) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            edges.push_back({ix, iy});
        } else {
            queries.push_back({op, {ix, iy}});
        }
    }
    
    auto result = solveQueries(n, edges, queries);
    
    for (int ans : result) {
        cout << ans << '\n';
    }
    
    return 0;
}