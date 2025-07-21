#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> occupied;
    set<pair<int64_t, int64_t>> attacked;

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        int64_t dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int64_t dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            int64_t x = a + dx[k];
            int64_t y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    set<pair<int64_t, int64_t>> total_invalid;
    total_invalid.insert(occupied.begin(), occupied.end());
    total_invalid.insert(attacked.begin(), attacked.end());

    int64_t answer = N * N - total_invalid.size();
    cout << answer << '\n';

    return 0;
}