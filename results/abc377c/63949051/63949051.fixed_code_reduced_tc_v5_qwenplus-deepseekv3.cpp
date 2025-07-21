#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> prohibited;
    vector<pair<ll, ll>> pieces(M);

    for (auto &p : pieces) {
        cin >> p.first >> p.second;
        prohibited.insert(p);
    }

    for (const auto &p : pieces) {
        ll i = p.first;
        ll j = p.second;

        // All possible knight moves
        vector<pair<ll, ll>> moves = {
            {i + 2, j + 1},
            {i + 1, j + 2},
            {i - 1, j + 2},
            {i - 2, j + 1},
            {i - 2, j - 1},
            {i - 1, j - 2},
            {i + 1, j - 2},
            {i + 2, j - 1}
        };

        for (const auto &move : moves) {
            ll x = move.first;
            ll y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                prohibited.insert(move);
            }
        }
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - prohibited.size();

    cout << safe_squares << endl;

    return 0;
}