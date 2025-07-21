#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N;
    int M;
    cin >> N >> M;

    // Set to store all forbidden positions (where a piece cannot be placed)
    unordered_set<string> forbidden;  // Using string as key to uniquely identify a position

    // The 8 possible attack moves of a knight-like piece
    vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;

        // Add current piece's position to forbidden set
        forbidden.insert(to_string(a) + "," + to_string(b));

        // For each attacking direction, add the corresponding target position
        for (auto [dx, dy] : directions) {
            ll na = a + dx;
            ll nb = b + dy;

            // Only add if it's within grid bounds
            if (na >= 1 && na <= N && nb >= 1 && nb <= N) {
                forbidden.insert(to_string(na) + "," + to_string(nb));
            }
        }
    }

    // Total number of cells: N*N
    // Subtract the number of forbidden cells
    cout << (N * N - (ll)forbidden.size()) << endl;

    return 0;
}