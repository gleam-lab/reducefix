#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<priority_queue<int, vector<int>, greater<int>>> top_k;

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
    if (top_k[u].size() < top_k[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    while (!top_k[v].empty()) {
        top_k[u].push(top_k[v].top());
        top_k[v].pop();
        if (top_k[u].size() > 10) {
            top_k[u].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    top_k.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_k[i].push(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            unite(a, b);
        } else {
            a = find(a);
            if (top_k[a].size() < b) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                while (!top_k[a].empty()) {
                    temp.push_back(top_k[a].top());
                    top_k[a].pop();
                }
                reverse(temp.begin(), temp.end());
                cout << temp[b - 1] << '\n';
                for (int num : temp) {
                    top_k[a].push(num);
                }
            }
        }
    }

    return 0;
}