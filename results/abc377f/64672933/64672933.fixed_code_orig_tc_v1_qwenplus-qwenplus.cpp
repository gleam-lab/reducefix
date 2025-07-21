#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;
    set<pair<long long, long long>> occupied;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    long long attacked = 0;

    // Count attacked cells on attacked rows
    attacked += rows.size() * N;

    // Count attacked cells on attacked columns
    attacked += cols.size() * N;

    // Count attacked cells on attacked diagonals (a + b)
    for (auto d : diag1) {
        long long low = max(1LL, d - N);
        long long high = min(N, d - 1);
        if (low <= high) {
            attacked += (high - low + 1);
        }
    }

    // Count attacked cells on attacked anti-diagonals (a - b)
    for (auto d : diag2) {
        long long low = max(1LL, 1 + d);
        long long high = min(N, N + d);
        if (low <= high) {
            attacked += (high - low + 1);
        }
    }

    // Remove over-counted cells that were counted more than once

    // Intersections: rows × columns
    for (auto r : rows) {
        for (auto c : cols) {
            attacked -= 1; // was double counted
        }
    }

    // Intersections: rows × diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            long long c = d - r;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Intersections: rows × diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Intersections: cols × diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            long long r = d - c;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Intersections: cols × diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            long long r = d + c;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Intersections: diag1 × diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                1 <= r && r <= N && 1 <= c && c <= N) {
                attacked -= 1;
            }
        }
    }

    // Now remove cells with pieces themselves
    attacked -= M;

    // Total unattacked empty squares
    long long total = N * N - attacked;

    cout << total << '\n';

    return 0;
}