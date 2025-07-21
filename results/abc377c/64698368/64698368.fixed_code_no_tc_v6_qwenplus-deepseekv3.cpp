#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> pieces(M);
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> occupied;

    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
        for (auto [dx, dy] : moves) {
            ll x = a + dx;
            ll y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    ll total = N * N;
    ll unsafe = 0;
    for (auto [x, y] : attacked) {
        if (occupied.find({x, y}) == occupied.end()) {
            unsafe++;
        }
    }
    unsafe += occupied.size();

    cout << total - unsafe << '\n';

    return 0;
}