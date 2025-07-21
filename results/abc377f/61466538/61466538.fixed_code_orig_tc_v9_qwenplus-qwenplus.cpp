#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool inBounds(ll x, ll n) {
    return 1 <= x && x <= n;
}

bool inBounds(pair<ll, ll> p, ll n) {
    return inBounds(p.first, n) && inBounds(p.second, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> pieces;
    set<ll> rows, cols, diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total cells
    ll total = N * N;

    // Remove cells attacked by rows
    total -= (ll)rows.size() * N;

    // Remove cells attacked by columns
    total -= (ll)cols.size() * N;

    // Add back intersection (attacked by both rows and columns)
    total += (ll)rows.size() * cols.size();

    // Now subtract diagonals
    auto processDiag = [&](const set<ll>& D, bool isAnti) {
        for (ll d : D) {
            ll cnt;
            if (isAnti) {
                // anti-diagonal: i - j = d
                cnt = N - abs(d);
            } else {
                // main diagonal: i + j = d
                if (d <= N)
                    cnt = d - 1;
                else
                    cnt = 2 * N - d + 1;
            }

            total -= cnt;

            // add back intersections with attacked rows/cols
            set<pair<ll, ll>> intersections;

            for (ll r : rows) {
                ll c = isAnti ? r - d : d - r;
                if (inBounds({r, c}, N))
                    intersections.insert({r, c});
            }

            for (ll c : cols) {
                ll r = isAnti ? c + d : d - c;
                if (inBounds({r, c}, N))
                    intersections.insert({r, c});
            }

            total += intersections.size();
        }
    };

    processDiag(diag1, true);  // anti-diagonals
    processDiag(diag2, false); // main diagonals

    cout << max(0LL, total) << endl;

    return 0;
}