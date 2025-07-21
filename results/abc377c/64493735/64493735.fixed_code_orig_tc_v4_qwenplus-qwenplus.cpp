#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, M;
    cin >> N >> M;

    // Store positions that cannot be used: existing pieces + their attackable positions
    unordered_set<int64_t> blocked;

    // Precompute the 8 possible attack directions
    const array<pair<int64_t, int64_t>, 8> deltas = {{
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    }};

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Add current piece's position (it's already taken)
        blocked.insert(a * 1'000'000'000 + b);

        // Add all 8 attackable positions
        for (const auto& [da, db] : deltas) {
            int64_t na = a + da;
            int64_t nb = b + db;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                blocked.insert(na * 1'000'000'000 + nb);
            }
        }
    }

    // Total available positions = total cells - blocked ones
    cout << (N * N - static_cast<int64_t>(blocked.size())) << '\n';

    return 0;
}