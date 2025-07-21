#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }

    ll total_safe = N * N;
    ll attacked = 0;

    // Subtract squares attacked by rows
    attacked += rows.size() * N;
    // Subtract squares attacked by columns
    attacked += cols.size() * N;
    // Subtract squares attacked by diag1 (i + j = k)
    for (ll k : diag1) {
        ll lower_i = max(1LL, k - N);
        ll upper_i = min(N, k - 1);
        if (upper_i >= lower_i) {
            attacked += (upper_i - lower_i + 1);
        }
    }
    // Subtract squares attacked by diag2 (i - j = k)
    for (ll k : diag2) {
        ll lower_i = max(1LL, 1 + k);
        ll upper_i = min(N, N + k);
        if (upper_i >= lower_i) {
            attacked += (upper_i - lower_i + 1);
        }
    }

    // Add back overlaps between rows and columns
    attacked -= rows.size() * cols.size();
    // Add back overlaps between rows and diag1
    for (ll k : diag1) {
        for (ll i : rows) {
            ll j = k - i;
            if (j >= 1 && j <= N && cols.count(j) == 0) {
                attacked -= 1;
            }
        }
    }
    // Add back overlaps between rows and diag2
    for (ll k : diag2) {
        for (ll i : rows) {
            ll j = i - k;
            if (j >= 1 && j <= N && cols.count(j) == 0) {
                attacked -= 1;
            }
        }
    }
    // Add back overlaps between columns and diag1
    for (ll k : diag1) {
        for (ll j : cols) {
            ll i = k - j;
            if (i >= 1 && i <= N && rows.count(i) == 0) {
                attacked -= 1;
            }
        }
    }
    // Add back overlaps between columns and diag2
    for (ll k : diag2) {
        for (ll j : cols) {
            ll i = k + j;
            if (i >= 1 && i <= N && rows.count(i) == 0) {
                attacked -= 1;
            }
        }
    }
    // Add back overlaps between diag1 and diag2
    for (ll k1 : diag1) {
        for (ll k2 : diag2) {
            ll i = (k1 + k2) / 2;
            ll j = (k1 - k2) / 2;
            if ((k1 + k2) % 2 == 0 && (k1 - k2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) == 0 && cols.count(j) == 0) {
                    attacked -= 1;
                }
            }
        }
    }

    // Finally, subtract the M pieces themselves (if they were subtracted)
    total_safe = N * N - attacked - M;
    cout << total_safe << endl;
    return 0;
}