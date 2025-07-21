#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    set<int> diag1, diag2; // diag1: i + j, diag2: i - j

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    int ans = (n - rows.size()) * (n - cols.size());

    // Now subtract points on diagonals that are not already excluded by row/col check
    map<int, int> diag1_count, diag2_count;

    for (auto [x, y] : pieces) {
        int d1 = x + y, d2 = x - y;
        diag1_count[d1]++;
        diag2_count[d2]++;
    }

    // Function to return number of integer points (i,j) such that i+j == d and 1 <= i,j <= n
    auto count_diag1 = [&](int d) -> int {
        int lo = max(1LL, d - n);
        int hi = min(n, d - 1);
        if (lo > hi) return 0;
        return hi - lo + 1;
    };

    // Function to return number of integer points (i,j) such that i-j == d and 1 <= i,j <= n
    auto count_diag2 = [&](int d) -> int {
        int lo_i = max(1LL, 1 + d);
        int hi_i = min(n, n + d);
        if (lo_i > hi_i) return 0;
        return hi_i - lo_i + 1;
    };

    set<int> processed_d1(diag1.begin(), diag1.end());
    set<int> processed_d2(diag2.begin(), diag2.end());

    // Subtract diagonal 1 (i+j = d)
    for (int d : diag1) {
        int total_points_on_line = count_diag1(d);
        set<int> affected_rows;
        set<int> affected_cols;

        for (int r : rows) {
            int c = d - r;
            if (1 <= c && c <= n) affected_rows.insert(r);
        }
        for (int c : cols) {
            int r = d - c;
            if (1 <= r && r <= n) affected_cols.insert(d - c);
        }

        set<int> combined;
        for (int r : affected_rows) combined.insert(r);
        for (int c : affected_cols) combined.insert(d - c);

        ans -= (total_points_on_line - combined.size());
    }

    // Subtract diagonal 2 (i-j = d)
    for (int d : diag2) {
        int total_points_on_line = count_diag2(d);
        set<int> affected_rows;
        set<int> affected_cols;

        for (int r : rows) {
            int c = r - d;
            if (1 <= c && c <= n) affected_rows.insert(r);
        }
        for (int c : cols) {
            int r = d + c;
            if (1 <= r && r <= n) affected_cols.insert(d + c);
        }

        set<int> combined;
        for (int r : affected_rows) combined.insert(r);
        for (int c : affected_cols) combined.insert(d + c);

        ans -= (total_points_on_line - combined.size());
    }

    // Finally, add back intersections between diagonals (some were double-counted)
    // Only for small M, so no problem
    set<pair<int, int>> attacked_points;
    for (auto [x, y] : pieces) {
        attacked_points.insert({x, y});
    }

    // Add all points on the attack lines
    for (auto [x, y] : pieces) {
        int d1 = x + y, d2 = x - y;

        // i + j == d1
        int lo = max(1LL, d1 - n);
        int hi = min(n, d1 - 1);
        for (int i = lo; i <= hi; ++i) {
            int j = d1 - i;
            if (1 <= j && j <= n) {
                attacked_points.insert({i, j});
            }
        }

        // i - j == d2
        int lo2 = max(1LL, 1 + d2);
        int hi2 = min(n, n + d2);
        for (int i = lo2; i <= hi2; ++i) {
            int j = i - d2;
            if (1 <= j && j <= n) {
                attacked_points.insert({i, j});
            }
        }
    }

    // Total safe empty squares = total safe - attacked ones + occupied ones (they were included in attacked_points)
    int total_safe = ans;
    int total_occupied = m;
    int final_answer = total_safe - (attacked_points.size() - total_occupied);

    cout << final_answer << endl;
}

signed main() {
    solve();
}