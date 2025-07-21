#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});
        // All 8 possible knight moves
        ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int k = 0; k < 8; ++k) {
            ll ni = a + dx[k] - 1;
            ll nj = b + dy[k] - 1;
            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                attacked.insert({ni, nj});
            }
        }
    }

    // The total safe squares are N*N minus the squares that are either occupied or attacked
    ll total_safe = N * N - (attacked.size() + pieces.size());
    for (auto p : pieces) {
        if (attacked.count(p)) {
            total_safe++;
        }
    }
    cout << total_safe << endl;
    return 0;
}