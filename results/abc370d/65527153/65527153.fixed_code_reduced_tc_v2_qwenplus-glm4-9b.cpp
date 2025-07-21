#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second

const int N = 200020;

struct Bomb {
    int r, c;
    bool operator>(const Bomb& other) const {
        if (c != other.c) return c > other.c;
        return r > other.r;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Bomb> bombs;
    bombs.reserve(q);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        bombs.push_back({r, c});
    }

    sort(bombs.begin(), bombs.end());

    vector<int> rowWalls(n + 1, 0), colWalls(m + 1, 0);
    ll remainingWalls = (ll)n * m;

    for (const auto& bomb : bombs) {
        int r = bomb.r, c = bomb.c;

        // Check if there's a wall at the bomb location
        if (rowWalls[r] == c - 1 && colWalls[c] == r - 1) {
            remainingWalls--; // Wall is destroyed
        } else {
            // Destroy walls above and below
            for (int i = (r > 1 ? r - 2 : 0); i <= (r < n ? r + 1 : n); ++i) {
                rowWalls[i]--;
                remainingWalls -= (rowWalls[i] < c);
            }

            // Destroy walls to the left and right
            for (int j = (c > 1 ? c - 2 : 0); j <= (c < m ? c + 1 : m); ++j) {
                colWalls[j]--;
                remainingWalls -= (colWalls[j] < r);
            }
        }
    }

    cout << remainingWalls << '\n';

    return 0;
}