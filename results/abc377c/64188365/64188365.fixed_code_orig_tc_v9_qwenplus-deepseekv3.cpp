#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> unsafe;
    set<pair<ll, ll>> original_pieces;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        original_pieces.emplace(a, b);
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1},
            {a + 1, b + 2},
            {a - 1, b + 2},
            {a - 2, b + 1},
            {a - 2, b - 1},
            {a - 1, b - 2},
            {a + 1, b - 2},
            {a + 2, b - 1}
        };
        for (const auto& move : moves) {
            if (move.first >= 1 && move.first <= N && move.second >= 1 && move.second <= N) {
                unsafe.insert(move);
            }
        }
    }

    ll total_unsafe = unsafe.size() + original_pieces.size();
    for (const auto& piece : original_pieces) {
        if (unsafe.find(piece) != unsafe.end()) {
            total_unsafe--;
        }
    }

    ll safe_positions = N * N - total_unsafe;
    cout << safe_positions << endl;

    return 0;
}