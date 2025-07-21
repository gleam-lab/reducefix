#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<pll> occupied;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of squares not in any attacked row or column
    ll total_safe = (N - (ll)rows.size()) * (N - (ll)cols.size());

    // Now subtract the squares that are on diagonals covered by any piece
    set<pll> attacked_by_diag;

    for (const auto& p : occupied) {
        ll x = p.first, y = p.second;

        // Diagonal 1: x - y
        ll d1 = x - y;
        for (auto r : rows) {
            ll c = r - d1;
            if (1 <= c && c <= N)
                attacked_by_diag.insert({r, c});
        }
        for (auto c : cols) {
            ll r = d1 + c;
            if (1 <= r && r <= N)
                attacked_by_diag.insert({r, c});
        }

        // Diagonal 2: x + y
        ll d2 = x + y;
        for (auto r : rows) {
            ll c = d2 - r;
            if (1 <= c && c <= N)
                attacked_by_diag.insert({r, c});
        }
        for (auto c : cols) {
            ll r = d2 - c;
            if (1 <= r && r <= N)
                attacked_by_diag.insert({r, c});
        }

        // Intersection of both diagonals from this piece and other diagonals
        for (auto od1 : diag1) {
            // Solve x - y = od1 and x + y = d2
            ll x_ = (d2 + od1) / 2;
            ll y_ = (d2 - od1) / 2;
            if ((d2 + od1) % 2 == 0 && (d2 - od1) % 2 == 0 &&
                1 <= x_ && x_ <= N && 1 <= y_ && y_ <= N)
                attacked_by_diag.insert({x_, y_});
        }

        for (auto od2 : diag2) {
            // Solve x + y = od2 and x - y = d1
            ll x_ = (od2 + d1) / 2;
            ll y_ = (od2 - d1) / 2;
            if ((od2 + d1) % 2 == 0 && (od2 - d1) % 2 == 0 &&
                1 <= x_ && x_ <= N && 1 <= y_ && y_ <= N)
                attacked_by_diag.insert({x_, y_});
        }
    }

    // Remove already occupied squares and those attacked by diagonal coverage
    for (const auto& p : occupied)
        attacked_by_diag.erase(p);

    // Subtract attacked positions
    total_safe -= (ll)attacked_by_diag.size();

    cout << max(0LL, total_safe) << "\n";

    return 0;
}