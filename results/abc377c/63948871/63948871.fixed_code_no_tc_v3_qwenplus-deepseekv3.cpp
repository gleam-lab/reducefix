#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long i64;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> occupied;
    set<pair<i64, i64>> threatened;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All possible moves a knight can capture from (a, b)
        vector<pair<i64, i64>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            i64 x = move.first;
            i64 y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    // Total squares: N*N
    // Invalid squares: occupied squares + threatened squares (but subtract overlaps)
    // First, merge all threatened squares
    for (const auto &p : occupied) {
        threatened.insert(p);
    }

    i64 ans = N * N - threatened.size();
    cout << ans << endl;

    return 0;
}