#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
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
    attacked -= row_count * col_count; // Intersection of rows and columns

    // Diagonals (i - j)
    for (ll d : diag1) {
        ll i_min, j_min, i_max, j_max;
        if (d >= 0) {
            i_min = 1 + d;
            j_min = 1;
            i_max = N;
            j_max = N - d;
        } else {
            i_min = 1;
            j_min = 1 - d;
            i_max = N + d;
            j_max = N;
        }
        ll cnt = min(i_max - i_min + 1, j_max - j_min + 1);
        if (cnt <= 0) continue;
        attacked += cnt;

        // Subtract intersections with rows and columns
        set<pair<ll, ll>> intersections;
        for (ll r : rows) {
            ll j = r - d;
            if (j >= 1 && j <= N) {
                intersections.insert({r, j});
            }
        }
        for (ll c : cols) {
            ll i = c + d;
            if (i >= 1 && i <= N) {
                intersections.insert({i, c});
            }
        }
        attacked -= intersections.size();
    }

    // Anti-diagonals (i + j)
    for (ll s : diag2) {
        ll i_min, j_min, i_max, j_max;
        if (s <= N + 1) {
            i_min = 1;
            j_min = s - 1;
            i_max = s - 1;
            j_max = 1;
        } else {
            i_min = s - N;
            j_min = N;
            i_max = N;
            j_max = s - N;
        }
        ll cnt = min(i_max - i_min + 1, j_max - j_min + 1);
        if (cnt <= 0) continue;
        attacked += cnt;

        // Subtract intersections with rows and columns
        set<pair<ll, ll>> intersections;
        for (ll r : rows) {
            ll j = s - r;
            if (j >= 1 && j <= N) {
                intersections.insert({r, j});
            }
        }
        for (ll c : cols) {
            ll i = s - c;
            if (i >= 1 && i <= N) {
                intersections.insert({i, c});
            }
        }
        // Also subtract intersections with diagonals (i - j)
        for (ll d : diag1) {
            ll i = (s + d) / 2;
            ll j = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                intersections.insert({i, j});
            }
        }
        attacked -= intersections.size();
    }

    // Subtract the queen positions themselves (they were counted multiple times)
    attacked -= M;

    ll total = N * N;
    ll safe = total - attacked;
    cout << safe << endl;

    return 0;
}