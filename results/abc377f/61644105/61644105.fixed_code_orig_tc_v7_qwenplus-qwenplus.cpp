#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    long long ans = N * N;
    ans -= N * (rows.size() + cols.size());
    ans -= (diag1.size() + diag2.size()) * N;
    ans += rows.size() * cols.size();
    ans += diag1.size() * diag2.size();

    // Intersections of row/col with diag1/diag2
    for (long long r : rows) {
        for (long long d1 : diag1) {
            long long c = r - d1;
            if (c >= 1 && c <= N) ans++;
        }
        for (long long d2 : diag2) {
            long long c = d2 - r;
            if (c >= 1 && c <= N) ans++;
        }
    }

    for (long long c : cols) {
        for (long long d1 : diag1) {
            long long r = d1 + c;
            if (r >= 1 && r <= N) ans++;
        }
        for (long long d2 : diag2) {
            long long r = d2 - c;
            if (r >= 1 && r <= N) ans++;
        }
    }

    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long r = (d2 + d1) / 2;
            long long c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) ans++;
        }
    }

    // Remove duplicates from triple overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            long long d1 = r - c;
            long long d2 = r + c;
            if (diag1.count(d1)) ans--;
            if (diag2.count(d2)) ans--;
        }
    }

    for (long long r : rows) {
        for (long long d1 : diag1) {
            long long c = r - d1;
            if (c >= 1 && c <= N && cols.count(c)) ans--;
        }
        for (long long d2 : diag2) {
            long long c = d2 - r;
            if (c >= 1 && c <= N && cols.count(c)) ans--;
        }
    }

    for (long long c : cols) {
        for (long long d1 : diag1) {
            long long r = d1 + c;
            if (r >= 1 && r <= N && rows.count(r)) ans--;
        }
        for (long long d2 : diag2) {
            long long r = d2 - c;
            if (r >= 1 && r <= N && rows.count(r)) ans--;
        }
    }

    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long r = (d2 + d1) / 2;
            long long c = (d2 - d1) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N &&
                rows.count(r) && cols.count(c)) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}