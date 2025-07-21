#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll attacked_rows = rows.size();
    ll attacked_cols = cols.size();
    ll attacked_diag1 = diag1.size();
    ll attacked_diag2 = diag2.size();

    ll total_attacked = attacked_rows * N + attacked_cols * (N - attacked_rows);
    
    // Calculate intersections for diagonals
    for (ll d : diag1) {
        ll lower_i = max(1LL, d - N);
        ll upper_i = min(N, d - 1);
        if (lower_i > upper_i) continue;
        ll cnt = upper_i - lower_i + 1;
        total_attacked += cnt;
    }

    for (ll d : diag2) {
        ll lower_i = max(1LL, 1 - d);
        ll upper_i = min(N, N - d);
        if (lower_i > upper_i) continue;
        ll cnt = upper_i - lower_i + 1;
        total_attacked += cnt;
    }

    // Subtract overlaps between rows/cols and diagonals
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                total_attacked -= 1;
            }
        }
    }

    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll i = (d1 + d2) / 2;
            ll j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) && cols.count(j)) {
                    total_attacked -= 1;
                }
            }
        }
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - total_attacked - M;
    cout << max(0LL, safe_squares) << endl;
    return 0;
}