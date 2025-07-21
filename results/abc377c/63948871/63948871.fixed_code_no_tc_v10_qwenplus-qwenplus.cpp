#include <iostream>
#include <set>
#include <utility>

using namespace std;

using i32 = int;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    i32 M;
    cin >> N >> M;

    set<pair<i64, i64>> forbidden; // Set to store positions that are either occupied or under attack

    // Define the 8 possible attack positions relative to (i,j)
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (i32 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;

        // Add current piece position
        forbidden.insert({a, b});

        // Add all positions that this piece can attack
        for (int k = 0; k < 8; ++k) {
            i64 ni = a + dx[k];
            i64 nj = b + dy[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                forbidden.insert({ni, nj});
            }
        }
    }

    // Total squares: N * N - number of forbidden squares
    cout << (N * N - static_cast<i64>(forbidden.size())) << '\n';

    return 0;
}