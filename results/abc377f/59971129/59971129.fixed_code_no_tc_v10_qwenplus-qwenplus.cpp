#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: a-b, diag2: a+b

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total safe squares = total empty squares not on any attacked line
    ll total_safe = (N - rows.size()) * (N - cols.size());

    // Now subtract the number of intersections between attacked diagonals and non-attacked rows/cols

    // For each diagonal of form a - b = d
    for (ll d : diag1) {
        // Equation: r - c = d => c = r - d
        ll count = 0;
        map<ll, bool> visited;

        // Count valid (r, c) = (r, r-d) where r is in [1,N] and c is in [1,N]
        for (ll r = max(1LL, d + 1); r <= min(N, N + d); ++r) {
            ll c = r - d;
            if (c < 1 || c > N) continue;
            if (!visited[r] && !rows.count(r)) {
                if (!visited[c] && !cols.count(c)) {
                    count++;
                }
            }
            visited[r] = true;
            visited[c] = true;
        }
        total_safe -= count;
    }

    // For each diagonal of form a + b = s
    for (ll s : diag2) {
        // Equation: r + c = s => c = s - r
        ll count = 0;
        map<ll, bool> visited;

        for (ll r = max(1LL, s - N); r <= min(N, s - 1); ++r) {
            ll c = s - r;
            if (c < 1 || c > N) continue;
            if (!visited[r] && !rows.count(r)) {
                if (!visited[c] && !cols.count(c)) {
                    count++;
                }
            }
            visited[r] = true;
            visited[c] = true;
        }
        total_safe -= count;
    }

    cout << total_safe << endl;
    return 0;
}