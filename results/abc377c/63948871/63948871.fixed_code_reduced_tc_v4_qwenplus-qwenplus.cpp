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

    set<pii> attacked_positions;

    // Define all 8 possible attack directions
    const vector<pii> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i64 i = 0; i < M; ++i) {
        i64 x, y;
        cin >> x >> y;

        // Add the piece itself to avoid placing there
        attacked_positions.insert({x, y});

        // Generate all positions that this piece can attack
        for (const auto& [dx, dy] : directions) {
            i64 nx = x + dx;
            i64 ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked_positions.insert({nx, ny});
            }
        }
    }

    // Calculate total number of safe positions
    i64 total_cells = N * N;
    i64 unsafe_cells = attacked_positions.size();
    i64 safe_cells = total_cells - unsafe_cells;

    cout << safe_cells << endl;

    return 0;
}