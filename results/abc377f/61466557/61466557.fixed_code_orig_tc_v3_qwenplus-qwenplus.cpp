#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_M = 1005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // i-j and i+j

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of safe positions
    ll total = N * N;

    // Subtract rows
    total -= (ll)rows.size() * N;

    // Subtract columns
    total -= (ll)cols.size() * N;

    // Add back intersection of rows and columns (double-counted)
    total += (ll)rows.size() * cols.size();

    // Subtract diagonals diag1
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= -(N - 1) && d <= N - 1) {
            if (abs(d) < N) {
                cnt = N - abs(d);
            }
            total -= cnt;

            // Add back overlap with rows and columns
            set<pair<ll, ll>> overlaps;
            for (auto r : rows) {
                ll c = r - d;
                if (c >= 1 && c <= N) overlaps.insert({r, c});
            }
            for (auto c : cols) {
                ll r = c + d;
                if (r >= 1 && r <= N) overlaps.insert({r, c});
            }
            total += overlaps.size();
        }
    }

    // Subtract diagonals diag2
    for (auto d : diag2) {
        ll cnt = 0;
        if (d >= 2 && d <= 2 * N) {
            if (d <= N + 1)
                cnt = d - 1;
            else
                cnt = 2 * N - d + 1;
            total -= cnt;

            // Add back overlap with rows, columns, and diag1
            set<pair<ll, ll>> overlaps;
            for (auto r : rows) {
                ll c = d - r;
                if (c >= 1 && c <= N) overlaps.insert({r, c});
            }
            for (auto c : cols) {
                ll r = d - c;
                if (r >= 1 && r <= N) overlaps.insert({r, c});
            }
            for (auto od : diag1) {
                // Solve:
                // i + j = d
                // i - j = od
                ll i = (d + od) / 2;
                ll j = (d - od) / 2;
                if ((d + od) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N)
                    overlaps.insert({i, j});
            }
            total += overlaps.size();
        }
    }

    cout << max(total, 0LL) << endl;

    return 0;
}