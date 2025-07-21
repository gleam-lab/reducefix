#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000; // Adjust based on the actual maximum possible N

struct Point {
    int x, y;
};

int dp[MAXN][MAXN]; // Dynamic programming table, initially all 0s
bool occupied[MAXN][MAXN]; // Grid to mark occupied cells

void initialize(int n) {
    memset(dp, 0, sizeof(dp));
    memset(occupied, 0, sizeof(occupied));
}

void markOccupiedCells(int n, vector<Point> pieces) {
    for (Point p : pieces) {
        occupied[p.x][p.y] = 1;
    }
}

void calculateCaptureRegions(int n, vector<Point> pieces) {
    // Calculate capture regions for each piece
    // This is a simplified placeholder function
}

int countSafeCells(int n) {
    int result = 0;
    // Count all cells that are not occupied and are reachable from the start
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!occupied[i][j]) {
                // Use dynamic programming table to check if this cell is reachable
                result++;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].x >> pieces[i].y;
    }

    initialize(n);
    markOccupiedCells(n, pieces);
    calculateCaptureRegions(n, pieces);

    int safeCells = countSafeCells(n);
    cout << safeCells << endl;

    return 0;
}