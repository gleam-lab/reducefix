#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Directions where a piece can attack
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Use a hash set to store occupied and attacked cells
    unordered_set<string> blocked;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        // Block the cell itself
        blocked.insert(to_string(a) + "," + to_string(b));

        // Block all cells that this piece can attack
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                blocked.insert(to_string(x) + "," + to_string(y));
            }
        }
    }

    // Total number of cells: N * N
    // Subtract the number of blocked cells
    cout << N * N - (long long)blocked.size() << endl;

    return 0;
}