#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    unordered_set<ll> rows, cols, diags1, diags2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
    }

    ll total = N * N;
    ll row_attacks = rows.size() * N;
    ll col_attacks = cols.size() * N;
    ll diag1_attacks = 0;
    for (ll d : diags1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        diag1_attacks += cnt;
    }
    ll diag2_attacks = 0;
    for (ll d : diags2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        diag2_attacks += cnt;
    }

    total -= row_attacks + col_attacks + diag1_attacks + diag2_attacks;

    // Add back intersections counted multiple times
    // Row and column intersections
    total += rows.size() * cols.size();

    // Row and diag1 intersections
    for (ll d : diags1) {
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                total++;
            }
        }
    }

    // Column and diag1 intersections
    for (ll d : diags1) {
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                total++;
            }
        }
    }

    // Row and diag2 intersections
    for (ll d : diags2) {
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                total++;
            }
        }
    }

    // Column and diag2 intersections
    for (ll d : diags2) {
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                total++;
            }
        }
    }

    // Diag1 and diag2 intersections
    for (ll d1 : diags1) {
        for (ll d2 : diags2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N) {
                total++;
            }
        }
    }

    // Subtract the original queens since they are not empty
    total -= M;

    cout << max(total, 0LL) << endl;

    return 0;
}