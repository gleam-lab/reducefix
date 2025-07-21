#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N;
    int M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> occupied;
    set<pair<int64_t, int64_t>> attacked;

    // The 8 possible knight-style moves
    vector<pair<int64_t, int64_t>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        occupied.emplace(a, b);

        // Mark all 8 possible attack positions
        for (auto [dx, dy] : moves) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.emplace(na, nb);
            }
        }
    }

    // Remove positions already occupied from attacked (they are not valid for placement)
    for (auto pos : occupied) {
        attacked.erase(pos);
    }

    int64_t total_squares = N * N;
    int64_t blocked = occupied.size() + attacked.size();

    cout << total_squares - blocked << '\n';

    return 0;
}