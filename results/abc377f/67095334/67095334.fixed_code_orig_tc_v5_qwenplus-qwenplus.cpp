#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;
    set<pair<long long, long long>> points;

    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
        points.insert({x, y});
    }

    // Total attacked cells
    long long attacked = 0;

    // Rows and columns
    attacked += (long long)rows.size() * N;
    attacked += (long long)cols.size() * N;

    // Diagonals of type x+y=d
    for (auto d : diag1) {
        long long len;
        if (d <= N + 1)
            len = d - 1;
        else
            len = 2 * N - d + 1;
        attacked += len;
    }

    // Diagonals of type x-y=d
    for (auto d : diag2) {
        long long len;
        if (d >= 0)
            len = N - d;
        else
            len = N + d;
        attacked += len;
    }

    // Overlaps: row & col
    for (auto r : rows)
        for (auto c : cols)
            if (points.find({r, c}) == points.end())
                attacked--;

    // Overlaps: row & diag1
    for (auto r : rows)
        for (auto d : diag1) {
            long long c = d - r;
            if (1 <= c && c <= N && points.find({r, c}) == points.end())
                attacked--;
        }

    // Overlaps: row & diag2
    for (auto r : rows)
        for (auto d : diag2) {
            long long c = d + r;
            if (1 <= c && c <= N && points.find({r, c}) == points.end())
                attacked--;
        }

    // Overlaps: col & diag1
    for (auto c : cols)
        for (auto d : diag1) {
            long long r = d - c;
            if (1 <= r && r <= N && points.find({r, c}) == points.end())
                attacked--;
        }

    // Overlaps: col & diag2
    for (auto c : cols)
        for (auto d : diag2) {
            long long r = d + c;
            if (1 <= r && r <= N && points.find({r, c}) == points.end())
                attacked--;
        }

    // Overlaps: diag1 & diag2
    for (auto d1 : diag1)
        for (auto d2 : diag2) {
            long long r = (d1 + d2) / 2;
            long long c = (d1 - d2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && points.find({r, c}) == points.end())
                attacked--;
        }

    // Total safe squares = all squares - occupied - attacked
    long long total = N * N - M - attacked;
    cout << total << endl;

    return 0;
}