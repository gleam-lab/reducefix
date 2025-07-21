#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using i32 = int;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    i32 M;
    cin >> N >> M;

    set<pair<i64, i64>> attacked_positions;

    // 8 possible knight move directions (relative positions)
    vector<pair<i64, i64>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i32 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Insert the current piece position to avoid placing our piece there
        attacked_positions.insert({a, b});

        // Check each of the 8 possible attack directions
        for (auto [dx, dy] : directions) {
            i64 x = a + dx;
            i64 y = b + dy;

            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_positions.insert({x, y});
            }
        }
    }

    // Total squares: N * N
    // We subtract the number of attacked positions and existing pieces
    // (attacked_positions includes both)
    cout << (N * N - static_cast<i64>(attacked_positions.size())) << '\n';

    return 0;
}