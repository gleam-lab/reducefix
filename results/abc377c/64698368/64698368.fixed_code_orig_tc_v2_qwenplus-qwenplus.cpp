#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Custom hash for pair<int, int>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<ll>()(static_cast<ll>(p.first) * 1000000007 + p.second);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<int, int>, hash_pair> attacked;

    // All 8 L-shaped moves a knight can make
    vector<pair<int, int>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        // For each piece, mark all cells it can attack
        for (auto [dx, dy] : knight_moves) {
            int x = a + dx;
            int y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.emplace(x, y);
            }
        }
    }

    // Total number of cells: N*N
    // Subtract number of attacked cells
    cout << (1LL * N * N - (ll)attacked.size()) << "\n";

    return 0;
}