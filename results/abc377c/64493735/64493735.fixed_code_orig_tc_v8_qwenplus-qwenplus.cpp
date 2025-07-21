#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked_positions;
    set<pair<long long, long long>> existing_pieces;

    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        for (auto [dx, dy] : directions) {
            long long na = a + dx;
            long long nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked_positions.insert({na, nb});
            }
        }
    }

    // Remove positions that are already occupied by existing pieces
    for (auto pos : existing_pieces) {
        attacked_positions.erase(pos);
    }

    // Total squares: N*N
    // Subtract number of existing pieces and attacked positions
    long long total_squares = N * N;
    long long blocked = existing_pieces.size() + attacked_positions.size();

    cout << total_squares - blocked << endl;

    return 0;
}