#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<long long, long long>> directions = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &dir : directions) {
            long long x = dir.first;
            long long y = dir.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total safe positions = N*N - (attacked positions + existing pieces)
    // But existing pieces might overlap with attacked positions, so we need to union them.
    set<pair<long long, long long>> unsafe;
    unsafe.insert(attacked.begin(), attacked.end());
    unsafe.insert(pieces.begin(), pieces.end());

    long long safe = N * N - unsafe.size();
    cout << safe << endl;

    return 0;
}