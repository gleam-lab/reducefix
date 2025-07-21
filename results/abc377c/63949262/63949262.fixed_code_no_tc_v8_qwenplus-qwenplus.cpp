#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using i64 = long long;
using Pii = pair<i64, i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or under attack
    set<Pii> attacked_or_occupied;

    // Directions as described in the problem
    vector<Pii> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Add the piece itself
        attacked_or_occupied.emplace(a, b);

        // Add all squares this piece can attack
        for (const auto& [dx, dy] : directions) {
            i64 x = a + dx;
            i64 y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked_or_occupied.emplace(x, y);
            }
        }
    }

    // Total cells - number of cells that are either occupied or under attack
    cout << (N * N - static_cast<i64>(attacked_or_occupied.size())) << '\n';

    return 0;
}