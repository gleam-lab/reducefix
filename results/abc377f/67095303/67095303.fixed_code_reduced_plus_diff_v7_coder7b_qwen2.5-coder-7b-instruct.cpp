#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> rows, cols, diag1, diag2;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    long long total_squares = n * n;
    long long captured_squares = 0;

    for (const auto& d1 : diag1) {
        captured_squares += min(n, d1);
        captured_squares -= rows.size();
    }

    for (const auto& d2 : diag2) {
        captured_squares += min(n, abs(d2));
        captured_squares -= cols.size();
    }

    cout << total_squares - captured_squares << endl;

    return 0;
}