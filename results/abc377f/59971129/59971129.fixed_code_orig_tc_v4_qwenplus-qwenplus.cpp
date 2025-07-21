#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<pair<ll, ll>> pieces;
    set<ll> diag1, diag2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    // Total number of cells not in any attacked row or column
    ll total = (N - (ll)rows.size()) * (N - (ll)cols.size());

    // Now subtract the number of empty squares on diagonals that are fully attacked

    // For diagonal type a - b = k
    map<pair<ll, ll>, bool> visited;
    for (ll d : diag1) {
        ll count = 0;
        // Intersect with rows and cols to find how many cells on this diagonal are already counted
        for (ll r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && !pieces.count({r, c})) {
                if (!visited[{r, c}]) {
                    ++count;
                    visited[{r, c}] = true;
                }
            }
        }
        for (ll c : cols) {
            ll r = d + c;
            if (r >= 1 && r <= N && !pieces.count({r, c})) {
                if (!visited[{r, c}]) {
                    ++count;
                    visited[{r, c}] = true;
                }
            }
        }
        total -= count;
        visited.clear();
    }

    // For diagonal type a + b = k
    for (ll d : diag2) {
        ll count = 0;
        for (ll r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N && !pieces.count({r, c})) {
                if (!visited[{r, c}]) {
                    ++count;
                    visited[{r, c}] = true;
                }
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N && !pieces.count({r, c})) {
                if (!visited[{r, c}]) {
                    ++count;
                    visited[{r, c}] = true;
                }
            }
        }

        // Also check intersection with other diagonals
        for (ll x : diag1) {
            ll a = (d + x) / 2;
            ll b = (d - x) / 2;
            if ((d + x) % 2 == 0 && (d - x) % 2 == 0 &&
                a >= 1 && a <= N && b >= 1 && b <= N &&
                !pieces.count({a, b}) && !visited[{a, b}]) {
                ++count;
                visited[{a, b}] = true;
            }
        }

        total -= count;
        visited.clear();
    }

    cout << total << endl;
    return 0;
}