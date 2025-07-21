#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    set<i64> rowSet, colSet, diag1Set, diag2Set;
    set<pair<i64, i64>> occupied;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rowSet.insert(a);
        colSet.insert(b);
        diag1Set.insert(a + b);
        diag2Set.insert(a - b);
        occupied.insert({a, b});
    }

    i64 totalThreatened = 0;

    // Rows and columns
    totalThreatened += rowSet.size() * N;
    totalThreatened += colSet.size() * N;

    // Diagonals
    totalThreatened += diag1Set.size() * N;
    totalThreatened += diag2Set.size() * N;

    // Overlaps between rows and diagonals
    for (auto r : rowSet) {
        for (auto d1 : diag1Set) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N)
                totalThreatened++;
        }
        for (auto d2 : diag2Set) {
            i64 c = r - d2;
            if (c >= 1 && c <= N)
                totalThreatened++;
        }
    }

    // Overlaps between columns and diagonals
    for (auto c : colSet) {
        for (auto d1 : diag1Set) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N)
                totalThreatened++;
        }
        for (auto d2 : diag2Set) {
            i64 r = d2 + c;
            if (r >= 1 && r <= N)
                totalThreatened++;
        }
    }

    // Overlaps between diagonal-diagonal intersections
    for (auto d1 : diag1Set) {
        for (auto d2 : diag2Set) {
            i64 x = (d1 + d2) / 2;
            i64 y = d1 - x;
            if (x >= 1 && y >= 1 && x <= N && y <= N)
                totalThreatened++;
        }
    }

    // Subtract overcounted cells where both row and column are covered
    for (auto r : rowSet) {
        for (auto c : colSet) {
            if (occupied.count({r, c}) == 0)
                totalThreatened--;
        }
    }

    // Subtract overcounted cells that lie on both diagonals from diag1 and diag2
    for (auto p : occupied) {
        i64 r = p.first, c = p.second;
        for (auto d1 : diag1Set) {
            if (r + c == d1) totalThreatened--;
        }
        for (auto d2 : diag2Set) {
            if (r - c == d2) totalThreatened--;
        }
    }

    // Now subtract overlapping cells between all pairs of attack patterns
    i64 totalCells = N * N;
    i64 ans = totalCells - totalThreatened - M;

    cout << ans << "\n";

    return 0;
}