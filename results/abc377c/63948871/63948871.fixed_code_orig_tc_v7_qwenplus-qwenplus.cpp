#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

// Define a hash function for pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()((ll)p.first << 32 | (ull)p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, PairHash> attacked;
    vector<pair<int, int>> dirs = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        // Add the current piece itself
        attacked.insert({x, y});
        // Add all squares that this piece can attack
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attacked.insert({nx, ny});
            }
        }
    }

    // Total number of cells minus the number of attacked or occupied cells
    cout << N * N - (ll)attacked.size() << "\n";
}