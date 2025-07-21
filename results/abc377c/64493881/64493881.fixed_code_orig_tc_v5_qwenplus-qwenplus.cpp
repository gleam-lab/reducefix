#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    // Set to store positions that cannot be used (occupied or under attack)
    set<pair<int64_t, int64_t>> forbidden;

    // Offsets representing the 8 knight-like moves described in the problem
    vector<pair<int64_t, int64_t>> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Add current piece's position (it's occupied, so forbidden)
        forbidden.emplace(a, b);

        // Add all positions that this piece can attack
        for (const auto& [dx, dy] : offsets) {
            int64_t na = a + dx;
            int64_t nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                forbidden.emplace(na, nb);
            }
        }
    }

    // Total valid positions = total grid cells - forbidden cells
    cout << (N * N - static_cast<int64_t>(forbidden.size())) << "\n";
    return 0;
}