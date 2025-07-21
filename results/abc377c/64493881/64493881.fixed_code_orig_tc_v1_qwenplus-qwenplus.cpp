#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attacked;

    vector<pair<long long, long long>> attack_offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        occupied.emplace(x, y);

        // Mark all 8 positions as attacked if valid
        for (auto [dx, dy] : attack_offsets) {
            long long nx = x + dx;
            long long ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                attacked.emplace(nx, ny);
            }
        }
    }

    // Remove positions already occupied since they are not considered "attacked"
    for (auto pos : occupied) {
        attacked.erase(pos);
    }

    // Total number of cells: N^2
    // Subtract number of occupied and attacked cells
    cout << (N * NLL - (long long)occupied.size() - (long long)attacked.size()) << '\n';

    return 0;
}