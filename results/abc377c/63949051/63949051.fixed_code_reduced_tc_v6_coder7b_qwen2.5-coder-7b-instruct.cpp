#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> attackedSquares;

    vector<pair<ll, ll>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;

        for (const auto& move : moves) {
            ll x = a + move.first;
            ll y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attackedSquares.insert({x, y});
            }
        }
    }

    ll usableSquares = N * N - attackedSquares.size();
    cout << usableSquares << endl;

    return 0;
}