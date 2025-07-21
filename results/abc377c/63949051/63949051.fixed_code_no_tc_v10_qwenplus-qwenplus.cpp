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

    // Directions a knight can move to capture other pieces
    const vector<pair<i32, i32>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    set<pair<i32, i32>> attacked_or_occupied;

    // Add all occupied squares and attacked squares to the set
    for (const auto &p : pieces) {
        attacked_or_occupied.insert(p); // current piece position is occupied

        for (const auto &d : directions) {
            i32 ni = p.first + d.first;
            i32 nj = p.second + d.second;

            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked_or_occupied.insert({ni, nj});
            }
        }
    }

    // Total number of squares is N * N
    // Subtract the number of squares that are either occupied or attacked
    i64 total_squares = static_cast<i64>(N) * N;
    i64 unavailable_squares = static_cast<i64>(attacked_or_occupied.size());

    cout << total_squares - unavailable_squares << endl;

    return 0;
}