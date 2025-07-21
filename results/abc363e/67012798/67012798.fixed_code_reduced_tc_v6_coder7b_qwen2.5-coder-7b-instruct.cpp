#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
int parent[MAXN * MAXN], rank[MAXN * MAXN];
int size[MAXN * MAXN];

void init() {
    for (int i = 0; i < H * W; ++i) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
            size[u] += size[v];
        } else {
            parent[u] = v;
            size[v] += size[u];
            if (rank[u] == rank[v]) {
                rank[v]++;
            }
        }
    }
}

bool isBorder(int i, int j) {
    return (i == 0 || i == H - 1 || j == 0 || j == W - 1);
}

int countConnectedComponents(int seaLevel) {
    init();
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= seaLevel && !isBorder(i, j)) {
                if (i > 0 && A[i - 1][j] <= seaLevel) unite(i * W + j, (i - 1) * W + j);
                if (i < H - 1 && A[i + 1][j] <= seaLevel) unite(i * W + j, (i + 1) * W + j);
                if (j > 0 && A[i][j - 1] <= seaLevel) unite(i * W + j, i * W + j - 1);
                if (j < W - 1 && A[i][j + 1] <= seaLevel) unite(i * W + j, i * W + j + 1);
            }
        }
    }
    unordered_set<int> seen;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= seaLevel && !isBorder(i, j)) {
                int root = find(i * W + j);
                if (seen.find(root) == seen.end()) {
                    seen.insert(root);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= Y; ++i) {
        cout << H * W - countConnectedComponents(i) << endl;
    }

    return 0;
}