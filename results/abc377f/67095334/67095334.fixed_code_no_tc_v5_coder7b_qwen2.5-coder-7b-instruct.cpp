#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (long long i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    long long ans = (N - rows.size()) * (N - cols.size());

    for (long long d : diag1) {
        set<long long> used;
        for (long long x : rows) {
            if (1 <= d - x && d - x <= N) {
                used.insert(x);
            }
        }
        for (long long y : cols) {
            if (1 <= d - y && d - y <= N) {
                used.insert(d - y);
            }
        }
        ans -= max(0LL, d - 1 - min(N, d)) - used.size();
    }

    for (long long d : diag2) {
        set<long long> used;
        for (long long x : rows) {
            if (1 <= x - d && x - d <= N) {
                used.insert(x);
            }
        }
        for (long long y : cols) {
            if (1 <= d + y && d + y <= N) {
                used.insert(d + y);
            }
        }
        ans -= max(0LL, d + N - max(1LL, d)) - used.size();
    }

    cout << ans << endl;

    return 0;
}