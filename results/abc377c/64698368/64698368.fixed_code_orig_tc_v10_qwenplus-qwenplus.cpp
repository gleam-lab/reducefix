#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    // Set to store all forbidden positions (including occupied ones)
    unordered_set<string> forbidden;

    // Directions in which a piece can attack
    const vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Convert to 0-based index
        x--; y--;

        // Mark this position as occupied
        forbidden.insert(to_string(x) + "," + to_string(y));

        // Mark all positions that this piece can attack
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                forbidden.insert(to_string(nx) + "," + to_string(ny));
            }
        }
    }

    // Total number of cells: N*N
    // Subtract number of forbidden cells
    cout << (N * N) - (ll)forbidden.size() << "\n";

    return 0;
}