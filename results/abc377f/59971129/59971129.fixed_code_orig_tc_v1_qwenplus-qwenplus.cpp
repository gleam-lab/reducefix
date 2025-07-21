#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mk make_pair

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<pair<ll, ll>> occupied;
    set<ll> diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r - c);
        diag2.insert(r + c);
        occupied.insert(mk(r, c));
    }

    // Total squares
    ll total = N * N;

    // Subtract rows and columns
    ll blocked_rows = rows.size();
    ll blocked_cols = cols.size();
    ll blocked_diag1 = diag1.size();
    ll blocked_diag2 = diag2.size();

    ll attacked_squares = 0;

    // Row and column attacks
    attacked_squares += blocked_rows * N;
    attacked_squares += blocked_cols * N;

    // Diagonal attacks
    for (auto d : diag1) {
        ll count = N - abs(d);
        if (count > 0) attacked_squares += count;
    }

    // Anti-diagonal attacks
    for (auto d : diag2) {
        ll count = N - abs(d - 2 * N + 1); // Adjusted formula to stay within bounds
        if (count > 0) attacked_squares += count;
    }

    // Inclusion-Exclusion: Add back overlaps between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (!occupied.count(mk(r, c))) {
                attacked_squares -= 1;
            }
        }
    }

    // Add back overlaps between rows and diagonals
    map<pair<ll, ll>, bool> overlap;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N && !occupied.count(mk(r, c)) && !overlap[mk(r, c)]) {
                overlap[mk(r, c)] = true;
                attacked_squares -= 1;
            }
        }
    }

    overlap.clear();

    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N && !occupied.count(mk(r, c)) && !overlap[mk(r, c)]) {
                overlap[mk(r, c)] = true;
                attacked_squares -= 1;
            }
        }
    }

    overlap.clear();

    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N && !occupied.count(mk(r, c)) && !overlap[mk(r, c)]) {
                overlap[mk(r, c)] = true;
                attacked_squares -= 1;
            }
        }
    }

    overlap.clear();

    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N && !occupied.count(mk(r, c)) && !overlap[mk(r, c)]) {
                overlap[mk(r, c)] = true;
                attacked_squares -= 1;
            }
        }
    }

    overlap.clear();

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && !occupied.count(mk(r, c)) && !overlap[mk(r, c)]) {
                overlap[mk(r, c)] = true;
                attacked_squares -= 1;
            }
        }
    }

    // Remove occupied positions from final result
    ll answer = total - attacked_squares - M;
    cout << max(0LL, answer) << '\n';

    return 0;
}