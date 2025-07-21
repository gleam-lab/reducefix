#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using i64 = long long;
using pii = pair<i64, i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pii> attacked_or_occupied;

    // The 8 possible attack patterns from a position
    const vector<pii> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i64 _ = 0; _ < M; ++_) {
        i64 a, b;
        cin >> a >> b;

        // Add the piece itself
        attacked_or_occupied.insert({a, b});

        // Add all potentially attacked squares
        for (auto [dx, dy] : directions) {
            i64 x = a + dx;
            i64 y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked_or_occupied.insert({x, y});
            }
        }
    }

    // Total number of safe cells = total cells - attacked/occupied cells
    i64 total_cells = N * N;
    i64 ans = total_cells - static_cast<i64>(attacked_or_occupied.size());

    cout << ans << endl;

    return 0;
}