#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    int M;
    cin >> N >> M;

    // Set to store all positions with a piece or under attack
    set<pair<ll, ll>> blocked;

    // Directions a piece can attack (like a knight)
    vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;

        // Insert all attacked positions
        for (auto [dx, dy] : directions) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                blocked.insert({nx, ny});
            }
        }

        // Also block the current piece's position
        blocked.insert({x, y});
    }

    // Total number of squares: N*N
    // Subtract the number of blocked (occupied or attacked) squares
    cout << (N * N) - (ll)blocked.size() << '\n';

    return 0;
}