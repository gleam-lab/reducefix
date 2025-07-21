#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> component[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (component[a].size() < component[b].size())
            swap(a, b);
        parent[b] = a;
        component[a].insert(component[a].end(), component[b].begin(), component[b].end());
        component[b].clear();
        sort(component[a].rbegin(), component[a].rend());
        if (component[a].size() > 10)
            component[a].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i] = {i};
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (component[root].size() < v) {
                cout << "-1\n";
            } else {
                cout << component[root][v - 1] << "\n";
            }
        }
    }

    return 0;
}