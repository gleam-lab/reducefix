#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> existing;
    set<pair<ll, ll>> unsafe;

    vector<pair<ll, ll>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        existing.insert({a, b});
        for (auto [dx, dy] : moves) {
            ll x = a + dx;
            ll y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                unsafe.insert({x, y});
            }
        }
    }

    ll total = N * N;
    ll unsafe_count = unsafe.size();
    ll existing_count = existing.size();

    // The safe squares are total squares minus existing squares minus unsafe squares not already existing
    // We need to subtract only the unique unsafe squares that are not existing
    for (auto [a, b] : existing) {
        if (unsafe.count({a, b})) {
            unsafe_count--;
        }
    }

    ll safe = total - existing_count - unsafe_count;
    cout << safe << endl;
    return 0;
}