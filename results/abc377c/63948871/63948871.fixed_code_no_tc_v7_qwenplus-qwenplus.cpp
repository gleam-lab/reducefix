#include <iostream>
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

    set<pair<i64, i64>> attacked_or_occupied;

    // The 8 possible attack moves (knight-style)
    const vector<pair<i64, i64>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i32 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Add the piece itself to the set (occupied)
        attacked_or_occupied.insert({a, b});

        // Add all positions that this piece can attack
        for (const auto& [dx, dy] : directions) {
            i64 na = a + dx;
            i64 nb = b + dy;
            if (na >= 1 && na <= N && nb >= 1 && nb <= N) {
                attacked_or_occupied.insert({na, nb});
            }
        }
    }

    // Total squares available = total grid size minus attacked/occupied squares
    cout << (N * N - static_cast<i64>(attacked_or_occupied.size())) << '\n';

    return 0;
}