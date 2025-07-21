#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<pair<ll, ll>> occupied;
    set<ll> diag1, diag2; // i-j, i+j

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll total_empty = N * N - occupied.size();

    // Remove all squares that are in attacked rows or columns
    ll safe_rows = N - rows.size();
    ll safe_cols = N - cols.size();
    ll ans = safe_rows * safe_cols;

    // Now subtract the squares that lie on any of the diagonals attacked by existing pieces
    set<pair<ll, ll>> attacked;

    // Process diagonal type 1: i-j = c => i-j == a-b for some (a,b)
    for (ll d : diag1) {
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                attacked.insert({r, c});
            }
        }
        for (ll c : cols) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                attacked.insert({r, c});
            }
        }
    }

    // Process diagonal type 2: i+j = s => i+j == a+b for some (a,b)
    for (ll s : diag2) {
        for (ll r : rows) {
            ll c = s - r;
            if (1 <= c && c <= N) {
                attacked.insert({r, c});
            }
        }
        for (ll c : cols) {
            ll r = s - c;
            if (1 <= r && r <= N) {
                attacked.insert({r, c});
            }
        }
    }

    // Remove attacked cells that were considered safe earlier
    for (auto &p : attacked) {
        if (rows.count(p.first) == 0 && cols.count(p.second) == 0) {
            --ans;
        }
    }

    // Also remove occupied cells from final answer
    cout << max((ll)0, ans - occupied.size()) << "\n";

    return 0;
}