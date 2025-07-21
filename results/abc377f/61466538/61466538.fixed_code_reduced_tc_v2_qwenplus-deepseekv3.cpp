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
    for (ll i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }

    unordered_set<ll> rows, cols, diag1, diag2;
    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = N * N;
    ll unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Subtract intersections of rows and columns

    // Diagonals (i - j)
    for (ll d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }

    // Diagonals (i + j)
    for (ll d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }

    // Subtract double-counted squares: intersections of diagonals with rows or columns
    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        // Check if the queen's position is at the intersection of a row, column, or both diagonals
        // These are already counted in the initial steps, so no need to adjust further
    }

    // Add back intersections between diagonals (i-j) and (i+j)
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 != 0 || (d2 - d1) % 2 != 0) continue;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) || cols.count(j)) {
                    // Already counted in row or column intersections
                    unsafe--;
                } else {
                    // Counted once in each diagonal, so subtract one to correct
                    unsafe--;
                }
            }
        }
    }

    // The answer is total squares minus unsafe squares minus the M squares already occupied
    ll answer = total - unsafe - M;
    cout << answer << endl;

    return 0;
}