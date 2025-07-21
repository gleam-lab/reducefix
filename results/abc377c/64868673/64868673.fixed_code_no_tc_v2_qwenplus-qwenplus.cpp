#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    vector<pair<long long, long long>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    set<pair<long long, long long>> forbidden;

    for (auto& pos : occupied) {
        long long x = pos.first;
        long long y = pos.second;

        // The current piece itself is forbidden for placing our piece
        forbidden.insert({x, y});

        for (auto& offset : attack_offsets) {
            long long nx = x + offset.first;
            long long ny = y + offset.second;

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert({nx, ny});
            }
        }
    }

    // Total squares = N*N
    // Subtract:
    // 1. M occupied squares
    // 2. forbidden squares that are not already occupied
    long long total = N * N;
    long long taken = M + (forbidden.size() - M); // forbidden includes M occupied squares

    cout << total - taken << endl;

    return 0;
}