#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long n, m;
vector<pair<int, int>> pieces;

set<int> rows, cols, diag1, diag2, anti_diag1, anti_diag2;

bool canPlace(int x, int y) {
    if (rows.count(x) > 0 || cols.count(y) > 0) return false;
    if (diag1.count(x + y) > 0 || diag2.count(x - y) > 0) return false;
    if (anti_diag1.count(x - y) > 0 || anti_diag2.count(x + y) > 0) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.push_back({x, y});
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
        anti_diag1.insert(x - y);
        anti_diag2.insert(x + y);
    }

    long long freeSquares = n * n;
    for (auto& p : pieces) {
        freeSquares--;
        int x = p.first;
        int y = p.second;

        // Check all squares in the same row
        for (int dy = 1; dy <= n; ++dy) {
            if (canPlace(x, y + dy)) break;
            freeSquares--;
        }
        for (int dy = -1; dy >= -n; --dy) {
            if (canPlace(x, y + dy)) break;
            freeSquares--;
        }

        // Check all squares in the same column
        for (int dx = 1; dx <= n; ++dx) {
            if (canPlace(x + dx, y)) break;
            freeSquares--;
        }
        for (int dx = -1; dx >= -n; --dx) {
            if (canPlace(x + dx, y)) break;
            freeSquares--;
        }

        // Check all squares in the same diagonal
        for (int dx = 1; dx <= n; ++dx) {
            if (canPlace(x + dx, y + dx)) break;
            freeSquares--;
        }
        for (int dx = -1; dx >= -n; --dx) {
            if (canPlace(x + dx, y + dx)) break;
            freeSquares--;
        }

        for (int dx = 1; dx <= n; ++dx) {
            if (canPlace(x + dx, y - dx)) break;
            freeSquares--;
        }
        for (int dx = -1; dx >= -n; --dx) {
            if (canPlace(x + dx, y - dx)) break;
            freeSquares--;
        }
    }

    cout << freeSquares << endl;
    return 0;
}