#include <iostream>
using namespace std;

long long n, m;
vector<pair<int, int>> pieces;

bool canPlacePiece(int x, int y) {
    for (auto &p : pieces) {
        int a = p.first, b = p.second;
        // Check if placing at (x, y) will be attacked by any piece at (a, b)
        if (x == a || y == b ||
            x + y == a + b || x - y == a - b) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
    }

    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (canPlacePiece(i, j)) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}