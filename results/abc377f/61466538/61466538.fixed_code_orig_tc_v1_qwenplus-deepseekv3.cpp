#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    attacked -= rows.size() * cols.size();

    // Diagonals (i - j)
    for (ll d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }

    // Diagonals (i + j)
    for (ll d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Subtract overlaps between rows/columns and diagonals
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (pieces.count({r, c}) == 0) {
                    attacked--;
                }
            }
        }
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (pieces.count({r, c}) == 0) {
                    attacked--;
                }
            }
        }
    }

    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                if (pieces.count({r, c}) == 0) {
                    attacked--;
                }
            }
        }
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (pieces.count({r, c}) == 0) {
                    attacked--;
                }
            }
        }
    }

    // Subtract overlaps between the two diagonals
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    if (pieces.count({r, c}) == 0) {
                        attacked--;
                    }
                }
            }
        }
    }

    // Subtract the existing pieces (they are not empty)
    attacked += M;

    ll safe = total - attacked;
    cout << max(safe, 0LL) << endl;

    return 0;
}