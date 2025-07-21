#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<priority_queue<int, vector<int>, greater<int>>> top_k;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (top_k[a].size() < top_k[b].size()) {
        swap(a, b);
    }
    parent[b] = a;
    priority_queue<int> temp;
    while (!top_k[b].empty()) {
        temp.push(top_k[b].top());
        top_k[b].pop();
    }
    while (!temp.empty()) {
        top_k[a].push(temp.top());
        temp.pop();
        if (top_k[a].size() > 10) {
            top_k[a].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    parent.resize(N + 1);
    top_k.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_k[i].push(i);
    }

    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (top_k[root].size() < v) {
                cout << -1 << '\n';
            } else {
                priority_queue<int> temp;
                while (top_k[root].size() > v) {
                    temp.push(top_k[root].top());
                    top_k[root].pop();
                }
                int ans = top_k[root].top();
                cout << ans << '\n';
                while (!temp.empty()) {
                    top_k[root].push(temp.top());
                    temp.pop();
                }
            }
        }
    }

    return 0;
}