#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<priority_queue<int, vector<int>, greater<int>>> topk; // Min-heap to keep top 10 largest

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
    if (topk[a].size() < topk[b].size()) {
        swap(a, b);
    }
    parent[b] = a;
    priority_queue<int> temp;
    while (!topk[b].empty()) {
        temp.push(topk[b].top());
        topk[b].pop();
    }
    while (!temp.empty()) {
        topk[a].push(temp.top());
        temp.pop();
        if (topk[a].size() > 10) {
            topk[a].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    topk.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        topk[i].push(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (topk[root].size() < v) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                while (topk[root].size() > v) {
                    temp.push_back(topk[root].top());
                    topk[root].pop();
                }
                cout << topk[root].top() << '\n';
                for (int x : temp) {
                    topk[root].push(x);
                }
                while (topk[root].size() > 10) {
                    topk[root].pop();
                }
            }
        }
    }

    return 0;
}