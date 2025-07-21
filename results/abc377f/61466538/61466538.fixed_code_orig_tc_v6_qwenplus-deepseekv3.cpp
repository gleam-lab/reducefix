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
    unsafe -= rows.size() * cols.size(); // Subtract intersections

    // Diagonals (a - b)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    // Anti-diagonals (a + b)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract squares counted in both diagonals and rows/columns
    for (auto d : diag1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    for (auto d : diag2) {
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
    }

    // Add back squares counted in both diagonals (i.e., intersections between diag1 and diag2)
    set<pair<ll, ll>> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0) {
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    intersections.insert({a, b});
                }
            }
        }
    }
    unsafe -= intersections.size();

    // Add back the squares that are occupied by existing pieces (since they were subtracted but are not available)
    unsafe += M;

    // Total safe squares = N^2 - unsafe
    ll safe = N * N - unsafe;
    cout << max(safe, 0LL) << endl;

    return 0;
}