// C - Avoid Knight Attack

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <tuple>
#include <cmath>

using namespace std;

#define i32 int
#define i64 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 N;
    i32 M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or can be attacked
    set<pair<i32, i32>> blocked;

    vector<pair<i32, i32>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (i32 m = 0; m < M; ++m) {
        i32 a, b;
        cin >> a >> b;

        // Add the piece itself
        blocked.insert({a, b});

        // Add all squares under attack by this piece
        for (auto [dx, dy] : deltas) {
            i32 x = a + dx;
            i32 y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                blocked.insert({x, y});
            }
        }
    }

    // Total number of squares: N * N
    // Subtract number of blocked/occupied squares
    i64 total_squares = (i64)N * N;
    i64 result = total_squares - (i64)blocked.size();

    cout << result << endl;

    return 0;
}