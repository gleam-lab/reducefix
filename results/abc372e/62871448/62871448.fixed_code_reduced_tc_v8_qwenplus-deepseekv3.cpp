#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (as[u].size() < as[v].size()) swap(u, v);
    fa[v] = u;
    priority_queue<int> pq;
    for (int x : as[u]) pq.push(x);
    for (int x : as[v]) pq.push(x);
    as[u].clear();
    while (!pq.empty() && as[u].size() < 10) {
        as[u].push_back(pq.top());
        pq.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        as[i].push_back(i);
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            u = find(u);
            if (as[u].size() < v) {
                cout << "-1\n";
            } else {
                cout << as[u][v-1] << "\n";
            }
        }
    }
    
    return 0;
}