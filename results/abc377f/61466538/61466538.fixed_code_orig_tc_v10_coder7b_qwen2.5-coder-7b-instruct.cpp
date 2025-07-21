#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    set<long long> rows, cols, diag1, diag2;
    unordered_set<pair<long long, long long>> placed;

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        placed.emplace(a, b);
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    long long total_squares = n * n;
    long long invalid_squares = 0;

    for (long long i = 1; i <= n; ++i) {
        if (rows.count(i)) {
            invalid_squares += n;
        }
        if (cols.count(i)) {
            invalid_squares += n;
        }
    }

    for (long long i = -n; i <= n; ++i) {
        if (diag1.count(i)) {
            invalid_squares += n;
        }
        if (diag2.count(i)) {
            invalid_squares += n;
        }
    }

    for (auto &[a, b] : placed) {
        invalid_squares -= 2;
    }

    cout << total_squares - invalid_squares / 2 << '\n';

    return 0;
}