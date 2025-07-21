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

    set<pair<i32, i32>> forbidden;
    pair<i32, i32> p;

    // Knight-like attack patterns (dx, dy)
    const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (i32 i = 0; i < M; ++i) {
        cin >> p.first >> p.second;
        forbidden.insert(p);

        for (int d = 0; d < 8; ++d) {
            int nx = p.first + dx[d];
            int ny = p.second + dy[d];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    cout << (static_cast<i64>(N) * static_cast<i64>(N) - forbidden.size());

    return 0;
}