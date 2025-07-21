#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using pii = pair<i32, i32>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 N;
    i32 M;
    cin >> N >> M;

    vector<pii> pieces(M);
    for (auto& p : pieces) {
        cin >> p.first >> p.second;
    }

    set<pii> attacked_or_occupied;

    // The 8 possible knight-like attack patterns
    const vector<pii> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (const auto& [x, y] : pieces) {
        // Add the piece itself as occupied
        attacked_or_occupied.insert({x, y});

        for (const auto& [dx, dy] : directions) {
            i32 nx = x + dx;
            i32 ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked_or_occupied.insert({nx, ny});
            }
        }
    }

    // Total squares - attacked/occupied squares
    cout << (1LL * N * N - static_cast<i64>(attacked_or_occupied.size())) << '\n';

    return 0;
}