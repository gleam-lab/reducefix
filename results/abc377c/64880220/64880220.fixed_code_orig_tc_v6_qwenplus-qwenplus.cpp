#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store all occupied squares and attacked squares
    set<pair<long long, long long>> occupied;

    // Possible attack directions (dx, dy)
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    // For each piece, mark the squares it can attack that are within bounds
    for (const auto& [x, y] : occupied) {
        for (const auto& [dx, dy] : directions) {
            long long nx = x + dx;
            long long ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                occupied.insert({nx, ny});
            }
        }
    }

    // Total number of squares: N*N
    // Subtract number of occupied or attacked squares
    cout << (N * N - (long long)occupied.size()) << endl;

    return 0;
}