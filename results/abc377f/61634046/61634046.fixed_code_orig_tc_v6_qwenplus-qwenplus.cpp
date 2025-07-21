#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<long long> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        long long r, c;
        cin >> r >> c;
        rows.insert(r);
        cols.insert(c);
        diag1.insert(r + c);
        diag2.insert(r - c);
    }

    // Function to count number of attacked cells from a set of lines
    auto count_attack = [&](const set<long long>& s, long long limit) {
        return (long long)s.size() * limit - (long long)s.size() * (s.size() - 1);
    };

    // Count intersections between row and column
    long long rc_intersect = 0;
    for (auto r : rows) {
        if (cols.find(r) != cols.end()) rc_intersect++;
    }

    // Count intersections between row and diag1
    long long rd1_intersect = 0;
    for (auto r : rows) {
        long long d = r + 1;
        long long cnt = upper_bound(diag1.begin(), diag1.end(), r + N) -
                        lower_bound(diag1.begin(), diag1.end(), d);
        rd1_intersect += cnt;
    }

    // Count intersections between row and diag2
    long long rd2_intersect = 0;
    for (auto r : rows) {
        long long low = -(N - r), high = r - 1;
        long long cnt = upper_bound(diag2.begin(), diag2.end(), high) -
                        lower_bound(diag2.begin(), diag2.end(), low);
        rd2_intersect += cnt;
    }

    // Similar logic for col-diag1 and col-diag2
    long long cd1_intersect = 0;
    for (auto c : cols) {
        long long low = c, high = N + c;
        long long cnt = upper_bound(diag1.begin(), diag1.end(), high) -
                        lower_bound(diag1.begin(), diag1.end(), low);
        cd1_intersect += cnt;
    }

    long long cd2_intersect = 0;
    for (auto c : cols) {
        long long low = 1 - c, high = N - c;
        long long cnt = upper_bound(diag2.begin(), diag2.end(), high) -
                        lower_bound(diag2.begin(), diag2.end(), low);
        cd2_intersect += cnt;
    }

    // diag1-diag2 intersections
    long long d1d2_intersect = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            long long x = (d1 + d2) / 2;
            long long y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                d1d2_intersect++;
            }
        }
    }

    // Total number of attacked positions
    long long attacked =
        count_attack(rows, N) +
        count_attack(cols, N) +
        count_attack(diag1, N) +
        count_attack(diag2, 2 * N) -
        rc_intersect -
        rd1_intersect -
        rd2_intersect -
        cd1_intersect -
        cd2_intersect +
        d1d2_intersect;

    cout << N * N - M - attacked << endl;

    return 0;
}