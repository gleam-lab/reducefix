#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attacked;

    // All 8 possible L-shaped moves
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.emplace(a, b);
    }

    // For each piece, mark the squares it can attack
    for (const auto& pos : occupied) {
        long long x = pos.first;
        long long y = pos.second;

        for (const auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.emplace(nx, ny);
            }
        }
    }

    // Remove occupied squares from attacked set (they can't be used anyway)
    for (const auto& pos : occupied) {
        attacked.erase(pos);
    }

    // Total usable squares = total squares - (occupied + attacked)
    long long total_squares = N * N;
    long long blocked = occupied.size() + attacked.size();

    cout << total_squares - blocked << endl;

    return 0;
}