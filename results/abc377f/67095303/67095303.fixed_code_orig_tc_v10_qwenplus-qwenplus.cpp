#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i+j, diag2: i-j

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll totalEmpty = N * N - M;

    ll bad = 0;

    // Rows and Columns: every cell in these lines are unsafe
    bad += rows.size() * N;
    bad += cols.size() * N;

    // Diagonals: calculate number of cells on each diagonal
    for (ll d : diag1) {
        ll len;
        if (d <= N + 1) {
            len = d - 1;
        } else {
            len = 2 * N + 1 - d;
        }
        bad += len;
    }

    for (ll d : diag2) {
        ll len = N;
        bad += len;
    }

    // Now subtract overcounts: intersections between rows/cols/diag1/diag2

    // Intersections between rows and columns
    for (ll r : rows) {
        for (ll c : cols) {
            bad--;
        }
    }

    // Intersections between rows and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N) bad--;
        }
    }

    // Intersections between rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N) bad--;
        }
    }

    // Intersections between cols and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N) bad--;
        }
    }

    // Intersections between cols and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d + c;
            if (1 <= r && r <= N) bad--;
        }
    }

    // Intersections between diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                1 <= r && r <= N && 1 <= c && c <= N) {
                bad--;
            }
        }
    }

    // Finally, subtract bad positions from total empty ones
    cout << totalEmpty - bad << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}