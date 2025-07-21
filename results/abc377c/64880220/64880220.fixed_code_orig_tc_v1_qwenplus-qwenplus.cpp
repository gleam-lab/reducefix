#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store all positions that are either occupied by existing pieces or can be attacked
    set<pair<long long, long long>> blocked;

    // All 8 possible L-shaped knight moves (rotated versions of (i±2,j±1) etc.)
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        blocked.insert({a, b});

        // Mark all squares that this piece can attack
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                blocked.insert({x, y});
            }
        }
    }

    // Total number of cells minus the number of blocked/occupied cells
    cout << (N * N - (long long)blocked.size()) << endl;

    return 0;
}