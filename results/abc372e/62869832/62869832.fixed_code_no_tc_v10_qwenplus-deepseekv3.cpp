#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (as[x].size() < as[y].size()) {
        swap(x, y);
    }
    vector<int> merged;
    int i = 0, j = 0;
    while (i < as[x].size() && j < as[y].size() && merged.size() < 10) {
        if (as[x][i] > as[y][j]) {
            merged.push_back(as[x][i]);
            i++;
        } else {
            merged.push_back(as[y][j]);
            j++;
        }
    }
    while (i < as[x].size() && merged.size() < 10) {
        merged.push_back(as[x][i]);
        i++;
    }
    while (j < as[y].size() && merged.size() < 10) {
        merged.push_back(as[y][j]);
        j++;
    }
    as[x] = merged;
    fa[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        as[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            merge(u, v);
        } else {
            int root = find(u);
            if ((int)as[root].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }
    
    return 0;
}