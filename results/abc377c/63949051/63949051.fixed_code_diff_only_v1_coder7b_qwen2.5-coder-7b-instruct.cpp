#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    ll M;
    cin >> M;

    vector<pair<ll, ll>> pieces(M);
    for (ll i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Calculate the number of valid positions
    ll valid_positions = N * N;

    // Check each piece's possible moves
    for (const auto& piece : pieces) {
        ll x = piece.first, y = piece.second;

        // Check all possible knight moves
        vector<pair<ll, ll>> knight_moves = {
            {x + 2, y + 1}, {x + 1, y + 2}, {x - 1, y + 2}, {x - 2, y + 1},
            {x - 2, y - 1}, {x - 1, y - 2}, {x + 1, y - 2}, {x + 2, y - 1}
        };

        for (const auto& move : knight_moves) {
            ll nx = move.first, ny = move.second;

            // Check if the new position is within bounds and not already occupied
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                --valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}