#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> horizontals, verticals, diagonals1, diagonals2;
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        horizontals.insert(b);
        verticals.insert(a);
        diagonals1.insert(a + b);
        diagonals2.insert(a - b);
    }

    ll total_squares = N * N;
    ll capturable_squares = 0;

    capturable_squares += horizontals.size();
    capturable_squares += verticals.size();
    capturable_squares += diagonals1.size();
    capturable_squares += diagonals2.size();

    // Remove double-counted squares
    for (ll b : horizontals) {
        if (verticals.find(b) != verticals.end()) {
            --capturable_squares;
        }
    }

    for (ll a : verticals) {
        if (horizontals.find(a) != horizontals.end()) {
            --capturable_squares;
        }
    }

    for (ll sum : diagonals1) {
        if (diagonals2.find(sum) != diagonals2.end()) {
            --capturable_squares;
        }
    }

    for (ll diff : diagonals2) {
        if (diagonals1.find(diff) != diagonals1.end()) {
            --capturable_squares;
        }
    }

    cout << total_squares - capturable_squares << '\n';

    return 0;
}