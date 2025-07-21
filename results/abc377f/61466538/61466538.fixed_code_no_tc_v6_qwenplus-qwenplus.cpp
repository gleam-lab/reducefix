#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

set<ll> rows, cols;
set<ll> diag1, diag2; // i - j and i + j

bool inBounds(ll x, ll y, ll n) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total squares minus occupied ones
    ll totalEmpty = N * N - M;

    // Subtract all squares attacked by existing queens
    ll attacked = 0;

    // Rows and columns attack
    attacked += (ll)rows.size() * (N - cols.size());
    attacked += (ll)cols.size() * (N - rows.size());

    // Diagonal 1: i-j = constant
    for (ll d : diag1) {
        ll count;
        if (d >= 0) {
            ll len = min(N, N - d);
            count = len;
        } else {
            ll len = min(N, N + d);
            count = len;
        }
        attacked += count;
    }

    // Diagonal 2: i+j = constant
    for (ll d : diag2) {
        ll count;
        if (d <= N)
            count = d;
        else
            count = 2 * N - d;
        attacked += count;
    }

    // Overlap correction between row/col and diagonals
    set<pll> overlapPoints;

    // Check intersections of rows with diagonal1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (inBounds(r, c, N)) overlapPoints.insert({r, c});
        }
    }

    // Check intersections of columns with diagonal1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (inBounds(r, c, N)) overlapPoints.insert({r, c});
        }
    }

    // Check intersections of rows with diagonal2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (inBounds(r, c, N)) overlapPoints.insert({r, c});
        }
    }

    // Check intersections of columns with diagonal2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (inBounds(r, c, N)) overlapPoints.insert({r, c});
        }
    }

    // Intersections between diagonal1 and diagonal2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && inBounds(r, c, N))
                overlapPoints.insert({r, c});
        }
    }

    // Remove overlaps from attacked count
    attacked -= overlapPoints.size();

    // Finally, subtract attacked empty cells from total empty cells
    cout << totalEmpty - attacked << endl;

    return 0;
}