#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

bool isValidMove(const set<pair<int, int>>& attackedPositions, const pair<int, int>& pos, int N) {
    return attackedPositions.find(pos) == attackedPositions.end();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    unordered_set<pair<int, int>> attackedPositions;

    vector<vector<int>> directions = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
    };

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based index

        for (const auto& dir : directions) {
            int x = a + dir[0], y = b + dir[1];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                attackedPositions.insert({x, y});
            }
        }
    }

    long long emptySquares = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (isValidMove(attackedPositions, {i, j}, n)) {
                ++emptySquares;
            }
        }
    }

    cout << emptySquares << endl;
    return 0;
}