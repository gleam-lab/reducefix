#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> existing_pieces;
    set<pair<ll, ll>> attacked_squares;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        existing_pieces.emplace(a, b);
        
        // Generate all 8 possible attack positions
        vector<pair<ll, ll>> directions = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto& [x, y] : directions) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (existing_pieces.find({x, y}) == existing_pieces.end()) {
                    attacked_squares.emplace(x, y);
                }
            }
        }
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - existing_pieces.size() - attacked_squares.size();
    cout << safe_squares << endl;
    
    return 0;
}