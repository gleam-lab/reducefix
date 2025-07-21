#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

vector<int> parent;
vector<multiset<int>> component;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (component[a].size() < component[b].size()) swap(a, b);
    for (int num : component[b]) {
        component[a].insert(num);
        if (component[a].size() > 10) {
            auto it = component[a].begin();
            component[a].erase(it);
        }
    }
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    component.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            merge(a, b);
        } else {
            int root = find(a);
            if (component[root].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].rbegin();
                advance(it, b - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}