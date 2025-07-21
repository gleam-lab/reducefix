#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m;
vector<pair<int, int>> pieces;

// Check if a position is safe from any piece
bool isSafe(int x, int y) {
    for (auto &p : pieces) {
        int a = p.first, b = p.second;
        // Check if x or y is in the same row or column
        if (a == x || b == y) return false;
        // Check diagonals
        if (abs(a - x) == abs(b - y)) return false;
    }
    return true;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        pieces.push_back({a, b});
    }

    long long emptyCount = 0;
    // Iterate over all grid positions
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (isSafe(i, j)) {
                emptyCount++;
            }
        }
    }

    printf("%lld\n", emptyCount);
    return 0;
}