#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked_positions;
    set<pair<long long, long long>> existing_pieces;

    // The 8 possible L-shaped moves
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.emplace(a, b);

        for (const auto& dir : directions) {
            long long ni = a + dir.first;
            long long nj = b + dir.second;
            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                attacked_positions.emplace(ni, nj);
            }
        }
    }

    // Subtract positions that are already occupied by existing pieces
    for (const auto& pos : existing_pieces) {
        attacked_positions.erase(pos);
    }

    // Total number of cells minus the number of unavailable cells:
    // - existing_pieces.size() is number of occupied cells
    // - attacked_positions.size() is number of cells under attack
    long long total_cells = N * N;
    long long unavailable = existing_pieces.size() + attacked_positions.size();

    cout << total_cells - unavailable << "\n";

    return 0;
}