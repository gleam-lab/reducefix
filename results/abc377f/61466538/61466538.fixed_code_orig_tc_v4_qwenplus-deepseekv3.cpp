#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pieces(M);
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();

    // Diagonals (i - j = d)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                intersections++;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                intersections++;
            }
        }
        // Subtract the intersections counted twice (both row and column)
        for (auto r : rows) {
            ll c = r - d;
            if (cols.find(c) != cols.end() && 1 <= c && c <= N) {
                intersections--;
            }
        }
        unsafe -= intersections;
    }

    // Diagonals (i + j = d)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                intersections++;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                intersections++;
            }
        }
        // Subtract the intersections counted twice (both row and column)
        for (auto r : rows) {
            ll c = d - r;
            if (cols.find(c) != cols.end() && 1 <= c && c <= N) {
                intersections--;
            }
        }
        unsafe -= intersections;
    }

    // Add back squares that were subtracted twice (intersection of two diagonals)
    set<pair<ll, ll>> diagonal_intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (1 <= i && i <= N && 1 <= j && j <= N) {
                    diagonal_intersections.insert({i, j});
                }
            }
        }
    }
    unsafe -= diagonal_intersections.size();

    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe;
    cout << max(safe, 0LL) << endl;

    return 0;
}