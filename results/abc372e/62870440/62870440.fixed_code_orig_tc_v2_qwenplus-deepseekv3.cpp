#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<priority_queue<int, vector<int>, greater<int>>> topK;

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
    if (topK[u].size() < topK[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    while (!topK[v].empty()) {
        topK[u].push(topK[v].top());
        topK[v].pop();
        if (topK[u].size() > 10) {
            topK[u].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    parent.resize(N + 1);
    topK.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        topK[i].push(i);
    }
    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (topK[root].size() < v) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                while (!topK[root].empty()) {
                    temp.push_back(topK[root].top());
                    topK[root].pop();
                }
                for (int num : temp) {
                    topK[root].push(num);
                }
                cout << temp[temp.size() - v] << "\n";
            }
        }
    }
    return 0;
}