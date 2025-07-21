#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> threatened;

    for (i64 k = 0; k < M; ++k) {
        i64 a, b;
        cin >> a >> b;

        threatened.insert({a, b});

        // All possible knight moves
        vector<pair<i64, i64>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto& move : moves) {
            i64 i = move.first;
            i64 j = move.second;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                threatened.insert({i, j});
            }
        }
    }

    i64 total_squares = N * N;
    i64 unsafe_squares = threatened.size();
    i64 safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << '\n';

    return 0;
}