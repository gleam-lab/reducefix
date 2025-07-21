#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> captured;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        captured.insert({a, b});
        // Calculate all 8 possible knight moves
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };
        for (auto &move : moves) {
            ll x = move.first, y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                captured.insert({x, y});
            }
        }
    }
    cout << N * N - captured.size() << endl;
}