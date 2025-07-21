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

    // Directions a knight can move that define the attacked positions
    const vector<pair<i32, i32>> directions = {
        {2, 1},
        {1, 2},
        {-1, 2},
        {-2, 1},
        {-2, -1},
        {-1, -2},
        {1, -2},
        {2, -1}
    };

    set<pair<i32, i32>> forbidden; // Set of cells that cannot be used

    // For each piece, mark all attacked squares and the piece's own square
    for (const auto &[x, y] : pieces) {
        forbidden.insert({x, y}); // Cannot place on a square with an existing piece

        for (const auto &[dx, dy] : directions) {
            i32 nx = x + dx;
            i32 ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total number of usable squares is total squares minus forbidden squares
    i64 total_squares = static_cast<i64>(N) * static_cast<i64>(N);
    cout << total_squares - static_cast<i64>(forbidden.size()) << endl;

    return 0;
}