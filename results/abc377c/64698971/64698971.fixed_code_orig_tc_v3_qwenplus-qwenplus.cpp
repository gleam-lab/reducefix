#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied, attacked;

    // Knight-style attack directions
    vector<pair<ll, ll>> dir = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int _ = 0; _ < M; ++_) {
        ll a, b;
        cin >> a >> b;
        --a; --b; // Convert to 0-based index
        occupied.insert({a, b});
        attacked.insert({a, b}); // Cannot place on existing pieces
        for (auto [dx, dy] : dir) {
            ll na = a + dx;
            ll nb = b + dy;
            if (0 <= na && na < N && 0 <= nb && nb < N) {
                attacked.insert({na, nb});
            }
        }
    }

    // Now calculate how many positions are NOT in attacked OR occupied
    ll total = N * N;
    ll blocked = 0;

    // First count unique blocked positions
    set<pair<ll, ll>> blockedPositions = attacked;
    cout << total - blockedPositions.size() << '\n';

    return 0;
}