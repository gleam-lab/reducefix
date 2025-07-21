#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 200005, MAX_L = 21;

int parent[MAX_V];
vector<int> children[MAX_V];
priority_queue<int, vector<int>, greater<int>> order[MAX_V];

void findSet(int x) {
    if (parent[x] == x) return;
    findSet(parent[x]);
    parent[x] = parent[parent[x]];  // Path compression
}

void unionSet(int u, int v) {
    findSet(u);
    findSet(v);
    parent[v] = u;
}

void addEdge(int u, int v) {
    if (!children[u].size()) order[u].push(max(u, v));
    if (!children[v].size()) order[v].push(max(u, v));
    unionSet(u, v);
    children[u].push_back(v);
    children[v].push_back(u);
}

int getKthLargest(int v, int k) {
    if (children[v].size() < k) return -1;
    int count = 0;
    while (!order[v].empty()) {
        int next = order[v].top();
        order[v].pop();
        if (++count == k) return next;
        if (!children[next].size()) order[next].push(next);
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int op, u, v, k;
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {
            addEdge(u, v);
        } else if (op == 2) {
            if (children[v].size() < k) {
                cout << -1 << endl;
            } else {
                cout << getKthLargest(v, k) << endl;
            }
        }
    }
    return 0;
}