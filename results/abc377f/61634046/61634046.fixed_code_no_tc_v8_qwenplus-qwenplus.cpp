#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 2000;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    set<int> rows, cols;
    set<long long> diag1, diag2;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(1LL * a + b);          // x + y
        diag2.insert(1LL * a - b);          // x - y
    }

    // Total squares minus occupied ones
    long long totalEmpty = N * N - M;

    // Subtract squares threatened in any direction
    long long threatenedByRow = N * rows.size();
    long long threatenedByCol = N * cols.size();
    long long threatenedByDiag1 = N * diag1.size();
    long long threatenedByDiag2 = N * diag2.size();

    // Inclusion-exclusion: add back overlaps of two directions
    long long overlapRowCol = 0LL;
    for (int r : rows) {
        for (int c : cols) {
            overlapRowCol++;
        }
    }

    long long overlapRowDiag1 = 0LL;
    for (int r : rows) {
        for (long long d : diag1) {
            int c = d - r;
            if (1 <= c && c <= N)
                overlapRowDiag1++;
        }
    }

    long long overlapRowDiag2 = 0LL;
    for (int r : rows) {
        for (long long d : diag2) {
            int c = r + d;
            if (1 <= c && c <= N)
                overlapRowDiag2++;
        }
    }

    long long overlapColDiag1 = 0LL;
    for (int c : cols) {
        for (long long d : diag1) {
            int r = d - c;
            if (1 <= r && r <= N)
                overlapColDiag1++;
        }
    }

    long long overlapColDiag2 = 0LL;
    for (int c : cols) {
        for (long long d : diag2) {
            int r = d + c;
            if (1 <= r && r <= N)
                overlapColDiag2++;
        }
    }

    long long overlapDiag1Diag2 = 0LL;
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            // Solve:
            // x + y = d1
            // x - y = d2
            long long x = (d1 + d2 + 1) / 2;
            long long y = d1 - x;
            if (1 <= x && x <= N && 1 <= y && y <= N)
                overlapDiag1Diag2++;
        }
    }

    // Inclusion-exclusion: subtract overlaps of three directions
    long long overlapRowColDiag1 = 0LL;
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(1LL * r + c))
                overlapRowColDiag1++;
        }
    }

    long long overlapRowColDiag2 = 0LL;
    for (int r : rows) {
        for (int c : cols) {
            if (diag2.count(1LL * r - c))
                overlapRowColDiag2++;
        }
    }

    long long overlapRowDiag1Diag2 = 0LL;
    for (int r : rows) {
        for (long long d1 : diag1) {
            int c = d1 - r;
            if (1 <= c && c <= N && diag2.count(1LL * r - c))
                overlapRowDiag1Diag2++;
        }
    }

    long long overlapColDiag1Diag2 = 0LL;
    for (int c : cols) {
        for (long long d1 : diag1) {
            int r = d1 - c;
            if (1 <= r && r <= N && diag2.count(1LL * r - c))
                overlapColDiag1Diag2++;
        }
    }

    // Inclusion-exclusion: add back overlaps of all four directions
    long long overlapAllFour = 0LL;
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(1LL * r + c) && diag2.count(1LL * r - c))
                overlapAllFour++;
        }
    }

    // Apply inclusion-exclusion principle
    long long threatened = threatenedByRow + threatenedByCol + threatenedByDiag1 + threatenedByDiag2
                         - overlapRowCol - overlapRowDiag1 - overlapRowDiag2 - overlapColDiag1 - overlapColDiag2 - overlapDiag1Diag2
                         + overlapRowColDiag1 + overlapRowColDiag2 + overlapRowDiag1Diag2 + overlapColDiag1Diag2
                         - overlapAllFour;

    cout << totalEmpty - threatened << endl;

    return 0;
}