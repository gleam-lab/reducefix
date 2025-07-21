#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

void solve() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    UnionFind uf(N * N);
    vector<vector<bool>> can_capture(N + 3, vector<bool>(N + 3, false));

    // Initialize capturing conditions
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if ((i >= 3 && j >= 2) || (i >= 2 && j >= 3)) {
                can_capture[i + 2][j + 1] = true;
            }
            if ((i >= 2 && j >= 3) || (i >= 3 && j >= 2)) {
                can_capture[i + 1][j + 2] = true;
            }
            if ((i >= 2 && j >= 2) || (i >= 3 && j >= 3)) {
                can_capture[i - 1][j + 2] = true;
            }
            // ... Add other capturing conditions similarly
        }
    }

    // Connect pieces that can capture each other
    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first - 1;
        int y = pieces[i].second - 1;
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (can_capture[x + dx + 2][y + dy + 2] && dx + 2 >= 1 && dx + 2 <= N && dy + 2 >= 1 && dy + 2 <= N) {
                    uf.unite(x * N + y, (x + dx) * N + (y + dy));
                }
            }
        }
    }

    // Count the number of safe squares
    long long safe_squares = 0;
    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first - 1;
        int y = pieces[i].second - 1;
        if (uf.find(x * N + y) != uf.find(0)) {
            // This piece is part of a group that can't capture the edge
            safe_squares += (N - x - 1) * (N - y - 1);
        }
    }

    cout << safe_squares << endl;
}

int main() {
    solve();
    return 0;
}