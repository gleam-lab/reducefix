#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> attacked;
    set<pair<ll, ll>> pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // Generate all 8 possible attack positions
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (auto [x, y] : moves) {
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // The total safe squares are N*N minus the attacked squares minus the existing pieces
    // But we must ensure existing pieces are not counted in attacked squares (though logically they might be)
    ll unsafe = attacked.size();
    ll total = N * N;
    ll safe = total - unsafe - M;

    // However, some existing pieces might be in attacked positions, but they are already occupied
    // So we just subtract the unique attacked positions and the existing pieces
    // Because existing pieces occupy squares, and attacked squares include those under threat
    // So safe squares = total - (attacked ∪ pieces).size()
    // But since pieces might be in attacked, we need to subtract only the unique elements in attacked and pieces
    set<pair<ll, ll>> all_unsafe;
    for (auto pos : attacked) {
        all_unsafe.insert(pos);
    }
    for (auto pos : pieces) {
        all_unsafe.insert(pos);
    }
    safe = total - all_unsafe.size();

    cout << safe << endl;
}