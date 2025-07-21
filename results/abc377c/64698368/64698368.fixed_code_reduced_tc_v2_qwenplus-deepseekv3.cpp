#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> threatened;
    set<pair<ll, ll>> occupied;

    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});

        for (auto move : moves) {
            ll x = a + move.first;
            ll y = b + move.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                threatened.insert({x, y});
            }
        }
    }

    // The squares to subtract are those that are either occupied or threatened.
    // But we need to ensure we don't double count squares that are both.
    ll total_safe = N * N;

    // First, count all squares that are either occupied or threatened.
    // To avoid double counting, we merge the sets and count unique entries.
    set<pair<ll, ll>> all_unsafe;
    all_unsafe.insert(occupied.begin(), occupied.end());
    all_unsafe.insert(threatened.begin(), threatened.end());

    total_safe -= all_unsafe.size();

    cout << total_safe << endl;

    return 0;
}