#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MAX_M 1003

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i-j, diag2: i+j

    vector<pii> pieces(M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert((ll)x - y);
        diag2.insert((ll)x + y);
    }

    // Total squares attacked by existing pieces
    ll totalAttacked = (ll)rows.size() * N + (ll)cols.size() * N +
                       (ll)diag1.size() * (2 * N - 1) +
                       (ll)diag2.size() * (2 * N - 1);

    // Subtract overlaps between row and column
    for (auto r : rows)
        for (auto c : cols)
            totalAttacked--;

    // Subtract overlaps between row and diag1
    for (auto r : rows)
        for (auto d : diag1)
            if ((d + r) >= 1 && (d + r) <= N)
                totalAttacked--;

    // Subtract overlaps between row and diag2
    for (auto r : rows)
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= N)
                totalAttacked--;
        }

    // Subtract overlaps between col and diag1
    for (auto c : cols)
        for (auto d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= N)
                totalAttacked--;
        }

    // Subtract overlaps between col and diag2
    for (auto c : cols)
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= N)
                totalAttacked--;
        }

    // Subtract overlaps between diag1 and diag2
    for (auto d1 : diag1)
        for (auto d2 : diag2) {
            ll r = (d2 + d1) / 2;
            ll c = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N)
                totalAttacked--;
        }

    // Add back overlaps of row, col, and diag1
    for (auto [x, y] : pieces)
        if (rows.count(x) && cols.count(y) && diag1.count((ll)x - y))
            totalAttacked++;

    // Add back overlaps of row, col, and diag2
    for (auto [x, y] : pieces)
        if (rows.count(x) && cols.count(y) && diag2.count((ll)x + y))
            totalAttacked++;

    // Add back overlaps of row, diag1, diag2
    for (auto [x, y] : pieces)
        if (rows.count(x) && diag1.count((ll)x - y) && diag2.count((ll)x + y))
            totalAttacked++;

    // Add back overlaps of col, diag1, diag2
    for (auto [x, y] : pieces)
        if (cols.count(y) && diag1.count((ll)x - y) && diag2.count((ll)x + y))
            totalAttacked++;

    // Subtract overlaps of all four: row, col, diag1, diag2
    for (auto [x, y] : pieces)
        if (rows.count(x) && cols.count(y) && diag1.count((ll)x - y) && diag2.count((ll)x + y))
            totalAttacked--;

    ll totalSquares = N * N;
    ll emptySquares = totalSquares - M;
    ll safeSquares = emptySquares - totalAttacked;

    cout << safeSquares << "\n";

    return 0;
}