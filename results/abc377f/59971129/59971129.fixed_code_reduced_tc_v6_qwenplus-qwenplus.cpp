#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mk make_pair

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: a-b, diag2: a+b

    map<pair<ll, ll>, bool> has_piece;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        has_piece[mk(a, b)] = true;
    }

    // Total squares not in any occupied row or column
    ll ans = (N - (ll)rows.size()) * (N - (ll)cols.size());

    // Subtract squares that can be attacked via diagonals or anti-diagonals

    // For each diagonal of the form a - b = d
    for (ll d : diag1) {
        ll count = 0;
        // Number of points on this diagonal
        ll len;
        if (d >= 0)
            len = min(N - d, N);
        else
            len = min(N + d, N);
        count = len;

        // subtract points already covered by rows and cols
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && !has_piece[mk(r, c)])
                --count;
        }
        for (ll c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N && !has_piece[mk(r, c)])
                --count;
        }

        // Remove overlapping with other diagonals
        for (ll s : diag2) {
            // intersection of a - b = d and a + b = s
            ll a = (s + d) / 2;
            ll b = s - a;
            if ((s + d) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N && !has_piece[mk(a, b)])
                --count;
        }

        ans -= count;
    }

    // For each anti-diagonal of the form a + b = s
    for (ll s : diag2) {
        ll count = 0;
        // Number of points on this diagonal
        ll len;
        if (s <= N + 1)
            len = s - 1;
        else
            len = 2 * N + 1 - s;
        count = len;

        // subtract points already covered by rows and cols
        for (ll r : rows) {
            ll c = s - r;
            if (c >= 1 && c <= N && !has_piece[mk(r, c)])
                --count;
        }
        for (ll c : cols) {
            ll r = s - c;
            if (r >= 1 && r <= N && !has_piece[mk(r, c)])
                --count;
        }

        // Remove overlapping with other diagonals
        for (ll d : diag1) {
            // intersection of a + b = s and a - b = d
            ll a = (s + d) / 2;
            ll b = s - a;
            if ((s + d) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N && !has_piece[mk(a, b)])
                --count;
        }

        ans -= count;
    }

    cout << ans << endl;
    return 0;
}