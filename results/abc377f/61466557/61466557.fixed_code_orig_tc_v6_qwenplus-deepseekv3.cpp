#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll unsafe = 0;
    
    // Calculate rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections counted twice

    // Calculate diagonals i - j = d
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d; // from (1 + d, 1) to (N, N - d)
        } else {
            cnt = N + d; // from (1, 1 - d) to (N + d, N)
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0) {
                unsafe--;
            }
        }
        
        // Subtract intersections with other diagonals (i + j = d2)
        for (auto d2 : diag2) {
            if ((d2 + d) % 2 != 0) continue;
            ll i = (d2 + d) / 2;
            ll j = (d2 - d) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N && occupied.count({i, j}) == 0) {
                unsafe--;
            }
        }
    }

    // Calculate diagonals i + j = d
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1; // from (1, d - 1) to (d - 1, 1)
        } else {
            cnt = 2 * N - d + 1; // from (d - N, N) to (N, d - N)
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N && occupied.count({r, c}) == 0) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N && occupied.count({r, c}) == 0) {
                unsafe--;
            }
        }
    }

    // Total squares is N*N - M (since M squares are occupied)
    ll total_safe = N * N - M - unsafe;
    cout << max(total_safe, 0LL) << endl; // Ensure non-negative result

    return 0;
}