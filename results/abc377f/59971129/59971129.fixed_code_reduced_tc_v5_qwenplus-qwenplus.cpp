#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define MAXM 1010

ll N, M;
set<ll> rows, cols;
set<ll> diag1, diag2; // diag1: i-j, diag2: i+j
map<pii, bool> blocked;

int main() {
    scanf("%lld%lld", &N, &M);
    
    rows.clear();
    cols.clear();
    diag1.clear();
    diag2.clear();
    
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        blocked[make_pair(a, b)] = true;
    }

    // Total empty squares = total squares - occupied
    ll total_empty = N * N - M;

    // Squares attacked by existing pieces
    set<ll> attacked_rows = rows;
    set<ll> attacked_cols = cols;
    set<ll> attacked_diag1 = diag1;
    set<ll> attacked_diag2 = diag2;

    // Count unique attacked squares
    set<pii> attacked_squares;
    
    // Process rows
    for (ll r : attacked_rows) {
        for (ll c = 1; c <= N; ++c) {
            attacked_squares.insert(make_pair(r, c));
        }
    }

    // Process columns
    for (ll c : attacked_cols) {
        for (ll r = 1; r <= N; ++r) {
            attacked_squares.insert(make_pair(r, c));
        }
    }

    // Process diagonal 1 (i-j)
    for (ll d : attacked_diag1) {
        // Points on diagonal i-j = d => i = j + d
        ll min_j = max(1LL, 1LL - d);
        ll max_j = min(N, N - d);
        for (ll j = min_j; j <= max_j; ++j) {
            ll i = j + d;
            attacked_squares.insert(make_pair(i, j));
        }
    }

    // Process diagonal 2 (i+j)
    for (ll s : attacked_diag2) {
        // Points on diagonal i+j = s => i = s-j
        ll min_j = max(1LL, s - N);
        ll max_j = min(N, s - 1);
        for (ll j = min_j; j <= max_j; ++j) {
            ll i = s - j;
            attacked_squares.insert(make_pair(i, j));
        }
    }

    // Remove occupied squares from attacked set
    for (ll i = 0; i < M; ++i) {
        pii pos = make_pair(a[i], b[i]);
        attacked_squares.erase(pos);
    }

    // Valid positions = Empty squares not in attacked_squares
    ll valid_positions = total_empty - attacked_squares.size();

    printf("%lld\n", valid_positions);

    return 0;
}