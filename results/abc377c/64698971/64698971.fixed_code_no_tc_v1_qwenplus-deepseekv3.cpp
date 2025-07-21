#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    set<pair<ll, ll>> unsafe;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        for (auto [dx, dy] : moves) {
            ll x = a + dx;
            ll y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    ll total_squares = N * N;
    ll occupied = M;
    ll unsafe_count = unsafe.size();
    for (auto [a, b] : pieces) {
        if (unsafe.count({a, b})) {
            unsafe_count--;
        }
    }

    ll safe_squares = total_squares - occupied - unsafe_count;
    cout << safe_squares << '\n';

    return 0;
}