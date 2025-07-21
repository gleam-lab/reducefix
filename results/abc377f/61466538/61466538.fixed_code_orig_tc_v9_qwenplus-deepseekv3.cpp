#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pieces(M);
    for (ll i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (auto &p : pieces) {
        ll a = p.first, b = p.second;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll attacked = 0;

    // Rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    attacked += row_count * N;
    attacked += col_count * N;
    attacked -= row_count * col_count;

    // Diagonals (type 1: a - b = constant)
    for (ll d : diag1) {
        ll cnt = 0;
        // The diagonal a - b = d can be represented as a = b + d
        // The bounds are 1 <= a <= N and 1 <= b <= N
        // So b + d >= 1 and b + d <= N => b >= 1 - d and b <= N - d
        // Also, b >= 1 and b <= N
        ll min_b = max(1LL, 1 - d);
        ll max_b = min(N, N - d);
        if (min_b > max_b) continue;
        cnt = max_b - min_b + 1;
        attacked += cnt;
    }

    // Diagonals (type 2: a + b = constant)
    for (ll d : diag2) {
        ll cnt = 0;
        // The diagonal a + b = d can be represented as a = d - b
        // The bounds are 1 <= a <= N and 1 <= b <= N
        // So d - b >= 1 and d - b <= N => b <= d - 1 and b >= d - N
        // Also, b >= 1 and b <= N
        ll min_b = max(1LL, d - N);
        ll max_b = min(N, d - 1);
        if (min_b > max_b) continue;
        cnt = max_b - min_b + 1;
        attacked += cnt;
    }

    // Now, find intersections between rows/columns and diagonals
    // And subtract the squares that were counted multiple times
    // We need to count squares that are in:
    // - a row and a diagonal (type 1 or type 2)
    // - a column and a diagonal (type 1 or type 2)
    // - both diagonals (type 1 and type 2)
    // But since rows and columns are handled first, we need to ensure no overcounting

    // Intersections between rows and diagonals (type 1)
    for (ll r : rows) {
        for (ll d : diag1) {
            ll b = r - d;
            if (b >= 1 && b <= N) {
                attacked--;
            }
        }
    }

    // Intersections between columns and diagonals (type 1)
    for (ll c : cols) {
        for (ll d : diag1) {
            ll a = c + d;
            if (a >= 1 && a <= N) {
                attacked--;
            }
        }
    }

    // Intersections between rows and diagonals (type 2)
    for (ll r : rows) {
        for (ll d : diag2) {
            ll b = d - r;
            if (b >= 1 && b <= N) {
                attacked--;
            }
        }
    }

    // Intersections between columns and diagonals (type 2)
    for (ll c : cols) {
        for (ll d : diag2) {
            ll a = d - c;
            if (a >= 1 && a <= N) {
                attacked--;
            }
        }
    }

    // Intersections between diagonals type 1 and type 2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    attacked--;
                }
            }
        }
    }

    // Total safe squares
    ll total = N * N - M;
    ll safe = total - attacked;

    // Ensure safe is non-negative
    safe = max(safe, 0LL);

    cout << safe << endl;

    return 0;
}