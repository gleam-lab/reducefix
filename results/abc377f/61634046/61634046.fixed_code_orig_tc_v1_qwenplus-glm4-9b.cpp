#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 1e9 + 5;

set<pair<int, int>> rowCaptures, colCaptures, diagCaptures1, diagCaptures2;

bool isCaptured(int x, int y) {
    return rowCaptures.count({x, y}) ||
           colCaptures.count({x, y}) ||
           diagCaptures1.count({x + y, y}) ||
           diagCaptures2.count({x - y, x});
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        rowCaptures.insert({x, y});
        colCaptures.insert({y, x});
        diagCaptures1.insert({x + y, y});
        diagCaptures2.insert({x - y, x});
    }

    long long totalSquares = n * n - (int) rowCaptures.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!isCaptured(i, j)) {
                totalSquares--;
            }
        }
    }

    cout << totalSquares << endl;
    return 0;
}