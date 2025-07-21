#include <bits/stdc++.h>

using namespace std;

void solve() {
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

    long long total_attacked = 0;

    // Rows
    total_attacked += (long long)rows.size() * N;

    // Columns
    total_attacked += (long long)cols.size() * N;

    // Diagonal 1: x - y
    for (auto d : diag1) {
        long long len = N - abs(d);
        if (len > 0)
            total_attacked += len;
    }

    // Diagonal 2: x + y
    for (auto d : diag2) {
        long long len = N - abs(N - d);
        if (len > 0)
            total_attacked += len;
    }

    // Intersections
    // Row & Column
    for (auto r : rows) {
        for (auto c : cols) {
            // (r, c) exists only once, so subtract 1 for every such pair
            total_attacked--;
        }
    }

    // Row & Diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            long long c = r - d;
            if (1 <= c && c <= N)
                total_attacked--;
        }
    }

    // Row & Diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            long long c = d - r;
            if (1 <= c && c <= N)
                total_attacked--;
        }
    }

    // Column & Diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            long long r = d + c;
            if (1 <= r && r <= N)
                total_attacked--;
        }
    }

    // Column & Diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            long long r = d - c;
            if (1 <= r && r <= N)
                total_attacked--;
        }
    }

    // Diag1 & Diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            long long r = (d1 + d2) / 2;
            long long c = d2 - r;
            if (1 <= r && r <= N && 1 <= c && c <= N)
                total_attacked--;
        }
    }

    // Add back triple intersections
    for (auto r : rows) {
        for (auto c : cols) {
            long long d1 = r - c;
            long long d2 = r + c;
            if (diag1.count(d1) && diag2.count(d2))
                total_attacked++;
        }
    }

    // Subtract quadruple intersections
    for (auto r : rows) {
        for (auto c : cols) {
            long long d1 = r - c;
            long long d2 = r + c;
            if (diag1.count(d1) && diag2.count(d2))
                total_attacked--;
        }
    }

    cout << N * N - total_attacked << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}