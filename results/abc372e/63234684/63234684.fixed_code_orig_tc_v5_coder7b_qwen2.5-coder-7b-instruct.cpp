#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;
        
        if(rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];
        if(rank[u] == rank[v]) rank[u]++;
    }

    int get_size(int u) {
        return size[find(u)];
    }
};

vector<vector<int>> adjList;

void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

vector<int> bfs(int start) {
    vector<int> dist(adjList.size(), INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : adjList[u]) {
            if(dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

vector<int> solveQueries(vector<vector<int>>& queries, int n) {
    UnionFind uf(n+1);
    adjList.assign(n+1, {});
    vector<int> result;
    
    for(auto& query : queries) {
        int type = query[0], u = query[1], v = query[2];
        if(type == 1) {
            addEdge(u, v);
            uf.unite(u, v);
        } else {
            int rootU = uf.find(u);
            vector<int> dist = bfs(rootU);
            if(dist[v] == INT_MAX || dist[v] == 0) {
                result.push_back(-1);
            } else {
                result.push_back(v);
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> queries(q, vector<int>(3));
    for(int i=0; i<q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> result = solveQueries(queries, n);

    for(auto& r : result) {
        cout << r << '\n';
    }

    return 0;
}