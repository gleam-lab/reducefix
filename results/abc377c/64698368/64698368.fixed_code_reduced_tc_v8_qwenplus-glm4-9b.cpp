#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

const int dx[] = {-1, -1, -2, -2, 1, 1, 2, 2};
const int dy[] = {2, -1, 1, -2, -2, -1, 1, 2};

void set_insert(vector<pair<ll, ll>>& grid, int a, int b) {
    ll max_row = min(N - 1, a + 3);
    ll min_row = max(0, a - 2);
    ll max_col = min(N - 1, b + 3);
    ll min_col = max(0, b - 2);

    for (ll i = min_row; i <= max_row; ++i) {
        for (ll j = min_col; j <= max_col; ++j) {
            grid[i * N + j] = {1, 0}; // Mark this cell as occupied by a piece
        }
    }
}

int main() {
    cin >> N >> M;
    set<pair<ll, ll>> grid(N * N, {0, 0});

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        set_insert(grid, a, b);
    }

    ll count = 0;
    for (auto& cell : grid) {
        if (cell.second == 0) count++; // Count empty cells
    }

    cout << count << endl;

    return 0;
}