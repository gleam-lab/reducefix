#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int MAXN = 2 * 100000 + 5;

struct Node {
    unordered_set<int> neighbors;
    priority_queue<int> pq;
};

Node nodes[MAXN];
int parent[MAXN], rank[MAXN];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rank[u] > rank[v]) {
        parent[v] = u;
        for (int neighbor : nodes[v].neighbors) {
            nodes[u].pq.push(nodes[v].pq.top());
            nodes[v].pq.pop();
        }
    } else {
        parent[u] = v;
        rank[v]++;
        for (int neighbor : nodes[u].neighbors) {
            nodes[v].pq.push(nodes[u].pq.top());
            nodes[u].pq.pop();
        }
    }
}

void addEdge(int u, int v) {
    nodes[u].neighbors.insert(v);
    nodes[v].neighbors.insert(u);
    merge(u, v);
}

int kthLargestDegree(int u, int k) {
    u = find(u);
    if (nodes[u].pq.size() < k) return -1;
    auto it = nodes[u].pq;
    while (--k) it++;
    return it.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> u >> k;
            cout << kthLargestDegree(u, k) << "\n";
        }
    }

    return 0;
}