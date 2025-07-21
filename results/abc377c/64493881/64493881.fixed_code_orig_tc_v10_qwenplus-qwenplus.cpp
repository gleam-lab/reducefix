#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    unordered_set<int64_t> attacked;
    unordered_set<int64_t> occupied;
    
    // Directions where a piece can attack
    array<pair<int64_t, int64_t>, 8> dirs = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        occupied.insert(a * 1000000000 + b);  // Unique key for each position

        // Mark all positions that this piece can attack
        for (const auto& [dx, dy] : dirs) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.insert(na * 1000000000 + nb);
            }
        }
    }

    // The answer is total squares minus occupied squares minus attacked squares
    int64_t total = N * N;
    int64_t ans = total - occupied.size() - attacked.size();

    cout << ans << endl;

    return 0;
}