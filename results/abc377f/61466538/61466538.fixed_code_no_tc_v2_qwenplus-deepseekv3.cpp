#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    unordered_set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        diag1.insert(queens[i].first - queens[i].second);
        diag2.insert(queens[i].first + queens[i].second);
    }

    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections

    // Diagonals (i - j)
    for (ll d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    // Diagonals (i + j)
    for (ll d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract intersections between rows/columns and diagonals
    for (const pll &q : queens) {
        ll i = q.first;
        ll j = q.second;
        // Intersection with row i
        if (rows.count(i)) {
            unsafe--;
        }
        // Intersection with column j
        if (cols.count(j)) {
            unsafe--;
        }
        // Intersection with diag1 (i-j)
        if (diag1.count(i - j)) {
            unsafe--;
        }
        // Intersection with diag2 (i+j)
        if (diag2.count(i + j)) {
            unsafe--;
        }
    }

    // Add back the intersections that were subtracted twice
    for (const pll &q : queens) {
        ll i = q.first;
        ll j = q.second;
        // Row and column
        if (rows.count(i) && cols.count(j)) {
            unsafe++;
        }
        // Row and diag1
        if (rows.count(i) && diag1.count(i - j)) {
            unsafe++;
        }
        // Row and diag2
        if (rows.count(i) && diag2.count(i + j)) {
            unsafe++;
        }
        // Column and diag1
        if (cols.count(j) && diag1.count(i - j)) {
            unsafe++;
        }
        // Column and diag2
        if (cols.count(j) && diag2.count(i + j)) {
            unsafe++;
        }
        // Diag1 and diag2
        if (diag1.count(i - j) && diag2.count(i + j)) {
            unsafe++;
        }
    }

    // Subtract the intersections that were added back three times
    for (const pll &q : queens) {
        ll i = q.first;
        ll j = q.second;
        if (rows.count(i) && cols.count(j) && diag1.count(i - j)) {
            unsafe--;
        }
        if (rows.count(i) && cols.count(j) && diag2.count(i + j)) {
            unsafe--;
        }
        if (rows.count(i) && diag1.count(i - j) && diag2.count(i + j)) {
            unsafe--;
        }
        if (cols.count(j) && diag1.count(i - j) && diag2.count(i + j)) {
            unsafe--;
        }
    }

    // Add the single square where all four conditions intersect
    for (const pll &q : queens) {
        ll i = q.first;
        ll j = q.second;
        if (rows.count(i) && cols.count(j) && diag1.count(i - j) && diag2.count(i + j)) {
            unsafe++;
        }
    }

    ll total = N * N;
    ll safe = total - unsafe;
    cout << safe << endl;

    return 0;
}