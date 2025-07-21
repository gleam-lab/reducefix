#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
int parent[MAXN * MAXN];
int rank[MAXN * MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[py] = px;
        rank[px]++;
    }
}

int get_index(int i, int j) {
    return i * W + j;
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize union-find
    for (int i = 0; i < H * W; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<vector<int>> grid(H, vector<int>(W, 0));

    for (int t = 1; t <= Y; ++t) {
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > t) {
                    grid[i][j] = 1;
                    count++;
                } else {
                    grid[i][j] = 0;
                }
            }
        }

        // Union adjacent cells
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] == 1) {
                    if (i > 0 && grid[i - 1][j] == 1) unite(get_index(i, j), get_index(i - 1, j));
                    if (j > 0 && grid[i][j - 1] == 1) unite(get_index(i, j), get_index(i, j - 1));
                }
            }
        }

        // Find the number of distinct components
        unordered_set<int> components;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] == 1) {
                    components.insert(find(get_index(i, j)));
                }
            }
        }

        cout << count - components.size() << endl;
    }

    return 0;
}