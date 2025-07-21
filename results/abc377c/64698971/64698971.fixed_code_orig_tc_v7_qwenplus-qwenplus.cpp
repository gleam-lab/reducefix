#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    // Use a hash set for faster lookup (avoiding log N factor from set)
    unordered_set<ll> attacked;

    vector<pair<int, int>> knight_moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b; // convert to 0-based index

        // Insert the piece itself
        attacked.insert(a * N + b);

        // Then mark all squares it can attack
        for (auto [dx, dy] : knight_moves) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                attacked.insert(na * N + nb);
            }
        }
    }

    // Total number of cells: N^2
    // Subtract the number of attacked or occupied cells
    cout << (N * N - (ll)attacked.size()) << endl;

    return 0;
}