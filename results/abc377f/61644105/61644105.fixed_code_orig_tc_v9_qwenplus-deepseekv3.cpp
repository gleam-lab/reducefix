#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> rows, cols, diag1, diag2;
    rows.reserve(M);
    cols.reserve(M);
    diag1.reserve(M);
    diag2.reserve(M);

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.push_back(a);
        cols.push_back(b);
        diag1.push_back(a + b);
        diag2.push_back(a - b);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());

    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    cols.erase(unique(cols.begin(), cols.end()), cols.end());
    diag1.erase(unique(diag1.begin(), diag1.end()), diag1.end());
    diag2.erase(unique(diag2.begin(), diag2.end()), diag2.end());

    ll total = N * N;
    ll unsafe = 0;

    unsafe += N * rows.size();
    unsafe += N * cols.size();
    for (ll d : diag1) {
        ll low = max(1LL, 1 + d - N);
        ll high = min(N, d - 1);
        if (low <= high) {
            unsafe += (high - low + 1);
        }
    }
    for (ll d : diag2) {
        ll low = max(1LL, 1 + d);
        ll high = min(N, N + d);
        if (low <= high) {
            unsafe += (high - low + 1);
        }
    }

    ll intersect_rows_cols = 0;
    for (ll r : rows) {
        for (ll c : cols) {
            if (binary_search(diag1.begin(), diag1.end(), r + c) &&
                binary_search(diag2.begin(), diag2.end(), r - c)) {
                intersect_rows_cols++;
            }
        }
    }

    ll intersect_rows_diag1 = 0;
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (1 <= c && c <= N && binary_search(cols.begin(), cols.end(), c)) {
                intersect_rows_diag1++;
            }
        }
    }

    ll intersect_rows_diag2 = 0;
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (1 <= c && c <= N && binary_search(cols.begin(), cols.end(), c)) {
                intersect_rows_diag2++;
            }
        }
    }

    ll intersect_cols_diag1 = 0;
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (1 <= r && r <= N && binary_search(rows.begin(), rows.end(), r)) {
                intersect_cols_diag1++;
            }
        }
    }

    ll intersect_cols_diag2 = 0;
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = c + d;
            if (1 <= r && r <= N && binary_search(rows.begin(), rows.end(), r)) {
                intersect_cols_diag2++;
            }
        }
    }

    ll intersect_diag1_diag2 = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N &&
                binary_search(rows.begin(), rows.end(), r) &&
                binary_search(cols.begin(), cols.end(), c)) {
                intersect_diag1_diag2++;
            }
        }
    }

    unsafe -= rows.size() * cols.size();
    unsafe -= intersect_rows_diag1;
    unsafe -= intersect_rows_diag2;
    unsafe -= intersect_cols_diag1;
    unsafe -= intersect_cols_diag2;
    unsafe += intersect_rows_cols;
    unsafe += intersect_diag1_diag2;

    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}