#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> pieces;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.emplace(a, b);

        // All possible attack positions
        vector<pair<long long, long long>> directions = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& [x, y] : directions) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.emplace(x, y);
            }
        }
    }

    // The total safe squares are N*N minus the number of unique squares in attacked or pieces
    long long total = N * N;
    for (const auto& p : pieces) {
        attacked.insert(p);
    }
    cout << total - attacked.size() << '\n';

    return 0;
}