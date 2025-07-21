#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store all positions that are either occupied or under attack
    unordered_set<string> attacked_or_occupied;

    // All 8 possible knight moves (L-shaped moves)
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Mark the current position as occupied
        string pos_key = to_string(a) + "," + to_string(b);
        attacked_or_occupied.insert(pos_key);

        // Generate all positions that this piece can attack
        for (const auto& [dx, dy] : directions) {
            int new_x = a + dx;
            int new_y = b + dy;

            if (1 <= new_x && new_x <= N && 1 <= new_y && new_y <= N) {
                string attacked_pos = to_string(new_x) + "," + to_string(new_y);
                attacked_or_occupied.insert(attacked_pos);
            }
        }
    }

    // Total number of cells = N*N
    // Subtract the number of cells that are either occupied or under attack
    cout << N * N - (long long)attacked_or_occupied.size() << endl;

    return 0;
}