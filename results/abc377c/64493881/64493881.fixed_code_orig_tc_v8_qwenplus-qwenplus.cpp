#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N;
    int M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> occupied;
    set<pair<int64_t, int64_t>> threatened;

    // Directions for threatening moves
    vector<pair<int64_t, int64_t>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // For each knight move, check if it's within bounds
        for (auto [dx, dy] : directions) {
            int64_t nx = a + dx;
            int64_t ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                threatened.insert({nx, ny});
            }
        }
    }

    // Count how many threatened positions are not occupied
    int64_t safe_positions = N * NLL * N * N - occupied.size();

    for (auto pos : threatened) {
        if (occupied.find(pos) == occupied.end()) {
            safe_positions--;
        }
    }

    cout << safe_positions << endl;

    return 0;
}