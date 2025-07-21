#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> existing_pieces;
    set<pair<ll, ll>> threatened;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        existing_pieces.emplace(a, b);

        // Check all 8 possible knight moves
        ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            ll x = a + dx[k];
            ll y = b + dy[k];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.emplace(x, y);
            }
        }
    }

    // The answer is total squares minus squares with existing pieces or threatened
    ll total_squares = N * N;
    ll unsafe_squares = existing_pieces.size();
    for (const auto& pos : threatened) {
        if (existing_pieces.find(pos) == existing_pieces.end()) {
            unsafe_squares++;
        }
    }

    cout << total_squares - unsafe_squares << endl;
    return 0;
}