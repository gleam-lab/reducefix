#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // The 8 possible attack positions relative to a knight
    vector<pair<long long, long long>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Set to store all forbidden cells (either occupied or under attack)
    unordered_set<string> forbidden;

    // Function to create a unique string key for a cell
    auto cell_key = [](long long x, long long y) {
        return to_string(x) + "," + to_string(y);
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Add the piece's position
        forbidden.insert(cell_key(a, b));

        // Add all potentially attacked cells from this piece
        for (auto [dx, dy] : attack_offsets) {
            long long nx = a + dx;
            long long ny = b + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                forbidden.insert(cell_key(nx, ny));
            }
        }
    }

    // The total number of cells that are either occupied or under attack
    long long forbidden_count = forbidden.size();

    // Total empty cells not under attack
    cout << (N * N - forbidden_count) << endl;

    return 0;
}