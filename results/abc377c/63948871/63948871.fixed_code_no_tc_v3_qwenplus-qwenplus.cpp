#include <iostream>
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

    set<pair<i32, i32>> forbidden; // Set to track squares that are either occupied or attacked

    // Define the 8 possible attack positions relative to a piece at (x, y)
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (i32 i = 0; i < M; ++i) {
        i32 x, y;
        cin >> x >> y;

        // Insert current piece position
        forbidden.emplace(x, y);

        // Check all 8 possible attack positions from this piece
        for (i32 j = 0; j < 8; ++j) {
            i32 nx = x + dx[j];
            i32 ny = y + dy[j];

            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                forbidden.emplace(nx, ny);
            }
        }
    }

    // Total squares - forbidden squares
    i64 total_squares = static_cast<i64>(N) * static_cast<i64>(N);
    i64 result = total_squares - static_cast<i64>(forbidden.size());

    cout << result << '\n';

    return 0;
}