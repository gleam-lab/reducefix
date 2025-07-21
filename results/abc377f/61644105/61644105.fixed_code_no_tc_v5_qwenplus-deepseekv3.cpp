#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Intersection of rows and columns

    // Diagonals 1 (a + b)
    for (ll d : diag1) {
        ll lower = max(1LL, d - N);
        ll upper = min(N, d - 1);
        if (lower <= upper) {
            unsafe += upper - lower + 1;
        }
    }

    // Diagonals 2 (a - b)
    for (ll d : diag2) {
        ll lower = max(1LL, 1 - d);
        ll upper = min(N, N - d);
        if (lower <= upper) {
            unsafe += upper - lower + 1;
        }
    }

    // Subtract intersections of rows and diagonals
    for (ll r : rows) {
        for (ll d : diag1) {
            ll b = d - r;
            if (1 <= b && b <= N && cols.count(b)) {
                unsafe--;
            }
        }
        for (ll d : diag2) {
            ll b = r - d;
            if (1 <= b && b <= N && cols.count(b)) {
                unsafe--;
            }
        }
    }

    // Subtract intersections of columns and diagonals
    for (ll c : cols) {
        for (ll d : diag1) {
            ll a = d - c;
            if (1 <= a && a <= N && rows.count(a)) {
                unsafe--;
            }
        }
        for (ll d : diag2) {
            ll a = c + d;
            if (1 <= a && a <= N && rows.count(a)) {
                unsafe--;
            }
        }
    }

    // Add intersections of rows, columns, and diagonals (subtracted too many times)
    for (ll r : rows) {
        for (ll c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                unsafe++;
            }
        }
    }

    ll total = N * N;
    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}