#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1000; // Maximum size of the grid after division
const int MAX_L = 20; // Maximum level for the tree

vector<vector<int>> grid(MAXN, vector<int>(MAXN));
vector<vector<int>> tree(4 * MAXN, vector<int>(MAXN, 0));
int n, m;

// Function to update the segment tree with the ID of a captured square
void update(int x, int y, int val) {
    x += MAXN;
    y += MAXN;
    for (int i = y; i >= 0; i -= -(i & -i)) {
        for (int j = x; j >= 0; j -= -(j & -j)) {
            tree[j][i] = val;
        }
    }
}

// Function to query the segment tree to check if a square is captured
bool query(int x, int y) {
    x += MAXN;
    y += MAXN;
    int captured = 0;
    for (int i = x; i < 2 * MAXN; i += -(i & -i)) {
        for (int j = y; j < 2 * MAXN; j += -(j & -j)) {
            captured |= tree[i][j];
        }
    }
    return captured;
}

// Function to process each block and update the global captured areas
void processBlock(int x, int y) {
    for (int i = 0; i < m; i++) {
        int ax = a[i] / n;
        int ay = b[i] / n;
        if (ax >= x && ax < x + 2 && ay >= y && ay < y + 2) {
            for (int dx = -2; dx <= 2; dx++) {
                for (int dy = -2; dy <= 2; dy++) {
                    int nx = ax + dx;
                    int ny = ay + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        update(nx * n + ny, ny, 1);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    n = pow(2, round(log2(n))); // Optimize grid size
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grid[a / n][b / n] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                processBlock(i, j);
            }
        }
    }

    int reachable = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (query(i * n + j, j * n + i) == 0) {
                reachable++;
            }
        }
    }

    cout << reachable;
    return 0;
}