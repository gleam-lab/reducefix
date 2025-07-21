#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied;
    set<pair<ll, ll>> attacked;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});

        // All 8 possible knight moves
        vector<pair<ll, ll>> moves = {
            {a + 2, b + 1}, {a + 1, b + 2},
            {a - 1, b + 2}, {a - 2, b + 1},
            {a - 2, b - 1}, {a - 1, b - 2},
            {a + 1, b - 2}, {a + 2, b - 1}
        };

        for (const auto &move : moves) {
            ll x = move.first;
            ll y = move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // The total unsafe squares are the union of occupied and attacked squares
    set<pair<ll, ll>> unsafe;
    unsafe.insert(occupied.begin(), occupied.end());
    unsafe.insert(attacked.begin(), attacked.end());

    ll safe_squares = N * N - unsafe.size();
    cout << safe_squares << endl;

    return 0;
}