#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<vector<int>> top;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (top[x].size() < top[y].size()) {
        swap(x, y);
    }
    vector<int> merged;
    merge(top[x].begin(), top[x].end(), top[y].begin(), top[y].end(), back_inserter(merged), greater<int>());
    if (merged.size() > 10) {
        merged.resize(10);
    }
    top[x] = merged;
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    parent.resize(N + 1);
    top.resize(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if (v > top[root].size()) {
                cout << "-1\n";
            } else {
                cout << top[root][v - 1] << "\n";
            }
        }
    }
    
    return 0;
}