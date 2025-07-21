#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
const int MAXE = 100000 + 5;
int parent[MAXE];
int rank[MAXE];
int h[MAXE];
int size[MAXN * MAXN];

struct UnionFind {
    void init(int n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
            h[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot != yRoot) {
            if (rank[xRoot] < rank[yRoot]) {
                parent[xRoot] = yRoot;
                size[yRoot] += size[xRoot];
                h[max(h[xRoot], h[yRoot])] += size[xRoot];
            } else if (rank[xRoot] > rank[yRoot]) {
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
                h[max(h[xRoot], h[yRoot])] += size[yRoot];
            } else {
                parent[yRoot] = xRoot;
                rank[xRoot]++;
                size[xRoot] += size[yRoot];
                h[max(h[xRoot], h[yRoot])] += size[yRoot];
            }
        }
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    UnionFind uf;
    uf.init(H * W);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            int idx = i * W + j;

            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                uf.merge(idx, A[i][j]);
            }
            if (i > 0) {
                uf.merge(idx, (i - 1) * W + j);
            }
            if (j > 0) {
                uf.merge(idx, i * W + j - 1);
            }
        }
    }

    int totalArea = H * W;
    for (int y = 1; y <= Y; y++) {
        int maxElevation = 0;
        for (int i = 0; i < H * W; i++) {
            int root = uf.find(i);
            maxElevation = max(maxElevation, max(h[i], uf.h[root]));
        }
        for (int i = 0; i < H * W; i++) {
            int root = uf.find(i);
            if (max(h[i], uf.h[root]) <= y) {
                totalArea -= size[root];
                uf.h[root] = y;
            }
        }
        cout << totalArea << endl;
    }

    return 0;
}