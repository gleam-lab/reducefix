#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
const int K = 10;

int fa[MAX_N];
vector<int> top[MAX_N];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (top[x].size() < top[y].size()) {
        swap(x, y);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while ((i < top[x].size() || j < top[y].size()) && merged.size() < K) {
        if (i < top[x].size() && (j >= top[y].size() || top[x][i] >= top[y][j])) {
            if (merged.empty() || merged.back() != top[x][i]) {
                merged.push_back(top[x][i]);
            }
            i++;
        } else {
            if (merged.empty() || merged.back() != top[y][j]) {
                merged.push_back(top[y][j]);
            }
            j++;
        }
    }
    top[x] = merged;
    fa[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
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
                cout << -1 << '\n';
            } else {
                cout << top[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}