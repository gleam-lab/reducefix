#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Define the maximum distance from a piece that can capture another piece.
const int MAX_RADIUS = 2;

bool canPlacePiece(int n, pair<int, int> occupied, pair<int, int> potential) {
    auto checkCapture = [&](int x, int y) -> bool {
        return occupied.first - MAX_RADIUS <= x && x <= occupied.first + MAX_RADIUS &&
               occupied.second - MAX_RADIUS <= y && y <= occupied.second + MAX_RADIUS;
    };

    return !checkCapture(potential.first + 2, potential.second + 1) &&
           !checkCapture(potential.first + 1, potential.second + 2) &&
           !checkCapture(potential.first - 1, potential.second + 2) &&
           !checkCapture(potential.first - 2, potential.second + 1) &&
           !checkCapture(potential.first - 2, potential.second - 1) &&
           !checkCapture(potential.first - 1, potential.second - 2) &&
           !checkCapture(potential.first + 1, potential.second - 2) &&
           !checkCapture(potential.first + 2, potential.second - 1);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> occupied(m);
    
    for (ll i = 0; i < m; ++i) {
        cin >> occupied[i].first >> occupied[i].second;
        occupied[i].first--; occupied[i].second--; // Convert to 0-based index
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (find(occupied.begin(), occupied.end(), {i, j}) == occupied.end()) {
                if (canPlacePiece(n, {i, j}, {i, j})) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}