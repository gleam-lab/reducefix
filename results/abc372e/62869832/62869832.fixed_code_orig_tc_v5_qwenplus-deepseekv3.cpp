#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> parent(MAXN);
vector<priority_queue<int, vector<int>, greater<int>>> top_k(MAXN);

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;

    if (top_k[root_u].size() < top_k[root_v].size()) {
        swap(root_u, root_v);
    }

    while (!top_k[root_v].empty()) {
        top_k[root_u].push(top_k[root_v].top());
        top_k[root_v].pop();
        if (top_k[root_u].size() > 10) {
            top_k[root_u].pop();
        }
    }
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_k[i].push(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (top_k[root].size() < v) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                while (top_k[root].size() > v) {
                    temp.push_back(top_k[root].top());
                    top_k[root].pop();
                }
                cout << top_k[root].top() << "\n";
                for (int x : temp) {
                    top_k[root].push(x);
                }
            }
        }
    }

    return 0;
}