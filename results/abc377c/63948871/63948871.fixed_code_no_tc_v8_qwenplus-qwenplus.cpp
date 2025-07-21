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

    set<pair<i64, i64>> attacked_or_occupied;

    // The 8 possible attack directions from a knight-like piece
    vector<pair<i64, i64>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i32 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Add the piece itself to occupied set
        attacked_or_occupied.insert({a, b});

        // Add all cells that this piece can attack
        for (const auto& [dx, dy] : directions) {
            i64 x = a + dx;
            i64 y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked_or_occupied.insert({x, y});
            }
        }
    }

    // Total number of squares is N*N
    // Subtract the number of attacked or occupied squares
    cout << (N * N - attacked_or_occupied.size()) << '\n';

    return 0;
}