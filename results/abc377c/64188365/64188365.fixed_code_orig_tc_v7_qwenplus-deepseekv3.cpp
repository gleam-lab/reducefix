#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> attacked;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});

        // All 8 possible knight moves
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            ll x = move.first;
            ll y = move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // The total bad squares are occupied squares plus attacked squares (without duplicates)
    set<pair<ll, ll>> bad_squares;
    bad_squares.insert(occupied.begin(), occupied.end());
    bad_squares.insert(attacked.begin(), attacked.end());

    ll safe_squares = N * N - bad_squares.size();
    cout << safe_squares << endl;

    return 0;
}