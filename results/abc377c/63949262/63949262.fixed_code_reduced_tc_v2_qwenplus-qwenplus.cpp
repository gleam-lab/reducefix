#include <iostream>
#include <vector>
#include <set>
#include <utility>

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

    // Knight move patterns relative to current position
    const vector<pair<i64, i64>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i32 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Add the piece itself to attacked set (cannot place on occupied squares)
        attacked_positions.insert({a, b});

        // Add all positions that this piece can attack
        for (const auto& [dx, dy] : attack_offsets) {
            i64 x = a + dx;
            i64 y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_positions.insert({x, y});
            }
        }
    }

    // Total number of valid positions is total grid size minus attacked/occupied positions
    cout << (N * N - static_cast<i64>(attacked_positions.size())) << '\n';

    return 0;
}