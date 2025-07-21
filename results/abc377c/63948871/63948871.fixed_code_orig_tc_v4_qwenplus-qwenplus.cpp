#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    int M;
    cin >> N >> M;

    // We will store attacked positions in a set to avoid duplicates
    set<pair<i64, i64>> attacked;

    const vector<pair<i64, i64>> directions{
        {2, 1},   {1, 2},   {-1, 2},  {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2},  {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        i64 x, y;
        cin >> x >> y;
        // Add the piece's position
        attacked.emplace(x, y);
        // Add all positions that this piece can attack
        for (auto [dx, dy] : directions) {
            i64 nx = x + dx;
            i64 ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked.emplace(nx, ny);
            }
        }
    }

    i64 total = N * N;
    i64 ans = total - static_cast<i64>(attacked.size());

    cout << ans << '\n';

    return 0;
}