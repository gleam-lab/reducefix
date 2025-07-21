#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> pieces;
    set<pair<int64_t, int64_t>> attacked;

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // All 8 possible attack positions
        int64_t dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int64_t dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int64_t x = a + dx[k];
            int64_t y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (pieces.find({x, y}) == pieces.end()) {
                    attacked.insert({x, y});
                }
            }
        }
    }

    int64_t total = N * N - M - attacked.size();
    cout << total << '\n';

    return 0;
}