#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pll> queens(M);
    for (ll i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }

    set<ll> rows;
    set<ll> cols;
    set<ll> diag1; // i - j
    set<ll> diag2; // i + j

    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        rows.insert(i);
        cols.insert(j);
        diag1.insert(i - j);
        diag2.insert(i + j);
    }

    ll total = N * N;
    ll attacked = 0;

    // Rows and columns
    ll row_count = rows.size();
    ll col_count = cols.size();
    attacked += row_count * N;
    attacked += col_count * N;
    attacked -= row_count * col_count;

    // Diagonals (i - j = d)
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        attacked += cnt;
    }

    // Diagonals (i + j = d)
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        attacked += cnt;
    }

    // Subtract overlaps between diagonals and rows/columns
    // Also subtract overlaps between the two diagonals (the intersection points)
    // To find the intersection points, for each queen, if it lies on both diagonals, it's already counted
    // But using inclusion-exclusion to avoid double counting
    set<pll> intersection_points;

    for (auto &q : queens) {
        ll i = q.first;
        ll j = q.second;
        intersection_points.insert({i, j});
    }

    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((i + j) == d2 && (i - j) == d1 && i >= 1 && i <= N && j >= 1 && j <= N) {
                intersection_points.insert({i, j});
            }
        }
    }

    attacked -= intersection_points.size();

    // The final answer is total squares minus attacked squares, plus any overlaps that were over-subtracted
    // But in the previous steps, we have already accounted for overlaps
    ll safe = total - attacked;
    cout << safe << endl;

    return 0;
}