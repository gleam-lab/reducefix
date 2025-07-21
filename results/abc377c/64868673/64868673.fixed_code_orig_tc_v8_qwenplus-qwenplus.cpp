#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> blocked;
    set<pair<long long, long long>> pieces;

    vector<pair<long long, long long>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
        blocked.emplace(a, b);

        for (const auto& [dx, dy] : knight_moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                blocked.emplace(x, y);
            }
        }
    }

    // Subtract the number of original pieces and the attacked squares that are inside the board
    cout << N * N - (long long)blocked.size() << endl;

    return 0;
}