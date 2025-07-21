#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total safe cells = total cells not in any attacked row/col/diag
    ll safe_cells = (N - (ll)rows.size()) * (N - (ll)cols.size());

    // Now subtract the intersections (cells on both a row and diagonal, etc.)

    // Use a set to track all attacked cells
    set<pair<ll, ll>> attacked;

    // Add all cells in attacked rows
    for (ll r : rows) {
        for (ll c : cols) {
            attacked.insert({r, c});
        }
    }

    // Add all cells in attacked diagonals of type i-j
    for (ll d : diag1) {
        // All (i,j) such that i-j = d => j = i-d
        // i must be between max(1, d+1) and min(N, N+d)
        for (ll i = max(1LL, d + 1); i <= min(N, N + d); ++i) {
            ll j = i - d;
            if (j >= 1 && j <= N) {
                attacked.insert({i, j});
            }
        }
    }

    // Add all cells in attacked diagonals of type i+j
    for (ll s : diag2) {
        // All (i,j) such that i+j = s => j = s-i
        for (ll i = max(1LL, s - N); i <= min(N, s - 1); ++i) {
            ll j = s - i;
            if (j >= 1 && j <= N) {
                attacked.insert({i, j});
            }
        }
    }

    // Remove the cells that are in attacked rows or columns
    for (ll r : rows) {
        for (ll j = 1; j <= N; ++j) {
            attacked.erase({r, j});
        }
    }
    for (ll c : cols) {
        for (ll i = 1; i <= N; ++i) {
            attacked.erase({i, c});
        }
    }

    // The remaining attacked cells must be subtracted from safe_cells
    safe_cells -= attacked.size();

    cout << safe_cells << endl;

    return 0;
}