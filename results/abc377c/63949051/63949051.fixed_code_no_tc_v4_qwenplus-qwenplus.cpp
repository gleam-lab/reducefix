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

    set<pair<i32, i32>> forbidden;

    // The 8 possible attack moves (dx, dy)
    const vector<pair<i32, i32>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (const auto &p : pieces) {
        forbidden.insert(p);  // The square with the existing piece cannot be used

        i32 x = p.first;
        i32 y = p.second;

        for (const auto &d : moves) {
            i32 nx = x + d.first;
            i32 ny = y + d.second;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total squares = N * N
    // Forbidden squares = forbidden.size()
    // Available squares = total - forbidden

    cout << (1LL * N * N - forbidden.size()) << '\n';

    return 0;
}