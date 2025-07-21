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

    i32 N;
    i32 M;
    cin >> N >> M;

    vector<pair<i32, i32>> pieces(M);
    for (auto &p : pieces) {
        cin >> p.first >> p.second;
    }

    // Directions that can be attacked
    const vector<pair<i32, i32>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    set<pair<i32, i32>> forbidden;

    for (const auto &[x, y] : pieces) {
        forbidden.insert({x, y});  // The cell itself is occupied

        for (const auto &[dx, dy] : directions) {
            i32 nx = x + dx;
            i32 ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total cells = N * N (use i64 to avoid overflow)
    i64 total_cells = static_cast<i64>(N) * static_cast<i64>(N);
    i64 result = total_cells - static_cast<i64>(forbidden.size());
    cout << result << '\n';

    return 0;
}