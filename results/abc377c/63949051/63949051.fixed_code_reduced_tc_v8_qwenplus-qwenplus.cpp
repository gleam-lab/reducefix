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
    for (auto& p : pieces) {
        cin >> p.first >> p.second;
    }

    set<pair<i32, i32>> forbidden;

    // The 8 possible attack directions
    const vector<pair<i32, i32>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (const auto& p : pieces) {
        forbidden.insert(p);  // The piece itself cannot be used

        for (const auto& d : directions) {
            i32 ni = p.first + d.first;
            i32 nj = p.second + d.second;

            if (1 <= ni && ni <= N && 1 <= nj && nj <= N) {
                forbidden.insert({ni, nj});
            }
        }
    }

    // Total number of cells: N * N
    // Subtract the number of forbidden cells
    cout << (i64)N * N - (i64)forbidden.size() << "\n";

    return 0;
}