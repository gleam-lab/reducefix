#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (auto &[a, b] : queens) {
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total_squares = N * N;
    ll attacked_squares = 0;

    // Rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    attacked_squares += row_count * N;
    attacked_squares += col_count * N;
    attacked_squares -= row_count * col_count;

    // Diagonals (a - b)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked_squares += cnt;
    }

    // Diagonals (a + b)
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked_squares += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    set<pll> intersections;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
        for (ll d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
        for (ll d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                intersections.insert({r, c});
            }
        }
    }

    // Subtract intersections between the two diagonals
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N) {
                intersections.insert({r, c});
            }
        }
    }

    attacked_squares -= intersections.size();

    // Add back the squares that are occupied by existing queens (since they are not empty)
    ll safe_squares = total_squares - attacked_squares - M;
    cout << safe_squares << endl;

    return 0;
}