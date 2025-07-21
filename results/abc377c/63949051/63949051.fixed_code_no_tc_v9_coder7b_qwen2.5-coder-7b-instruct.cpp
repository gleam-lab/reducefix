#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> pieces(M);
    for (ll i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Calculate the number of valid positions
    ll valid_positions = N * N;

    for (const auto& piece : pieces) {
        ll x = piece.first, y = piece.second;

        // Check positions within knight's move range
        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) == 3) {
                    ll nx = x + dx, ny = y + dy;
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        --valid_positions;
                    }
                }
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}