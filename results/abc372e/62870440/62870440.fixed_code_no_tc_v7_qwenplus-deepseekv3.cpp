#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int fa[MAXN];
priority_queue<int> components[MAXN];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    fa[v] = u;
    priority_queue<int> temp;
    while (!components[v].empty()) {
        temp.push(components[v].top());
        components[v].pop();
    }
    while (!temp.empty()) {
        if (components[u].size() < 10) {
            components[u].push(temp.top());
        } else if (temp.top() > components[u].top()) {
            components[u].pop();
            components[u].push(temp.top());
        }
        temp.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        components[i].push(i);
    }
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (components[root].size() < v) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                int res = -1;
                for (int i = 0; i < v; ++i) {
                    res = components[root].top();
                    temp.push_back(res);
                    components[root].pop();
                }
                cout << res << "\n";
                for (int num : temp) {
                    components[root].push(num);
                }
            }
        }
    }
    return 0;
}