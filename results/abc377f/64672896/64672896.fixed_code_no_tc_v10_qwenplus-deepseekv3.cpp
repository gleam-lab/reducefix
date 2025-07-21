#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 forbidden = 0;

    // Rows: N squares per row, |rows| rows
    forbidden += rows.size() * N;

    // Columns: N squares per column, |cols| columns
    forbidden += cols.size() * N;

    // Diagonals type 1 (i + j = c)
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_max >= x_min) {
            forbidden += x_max - x_min + 1;
        }
    }

    // Diagonals type 2 (i - j = c)
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_max >= x_min) {
            forbidden += x_max - x_min + 1;
        }
    }

    // Subtract intersections counted twice
    // Row and Column (a, b)
    forbidden -= rows.size() * cols.size();

    // Row and Diag1 (i + j = c) => j = c - i, i is fixed (row)
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 j = d - r;
            if (j >= 1 && j <= N && cols.count(j)) {
                forbidden--;
            }
        }
    }

    // Row and Diag2 (i - j = c) => j = i - c, i is fixed (row)
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 j = r - d;
            if (j >= 1 && j <= N && cols.count(j)) {
                forbidden--;
            }
        }
    }

    // Column and Diag1 (i + j = c) => i = c - j, j is fixed (column)
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 i = d - c;
            if (i >= 1 && i <= N && rows.count(i)) {
                forbidden--;
            }
        }
    }

    // Column and Diag2 (i - j = c) => i = j + c, j is fixed (column)
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 i = c + d;
            if (i >= 1 && i <= N && rows.count(i)) {
                forbidden--;
            }
        }
    }

    // Diag1 and Diag2 (i + j = c1, i - j = c2) => i = (c1 + c2)/2, j = (c1 - c2)/2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            i64 i = (d1 + d2) / 2;
            i64 j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N && rows.count(i) && cols.count(j)) {
                forbidden++;
            }
        }
    }

    // The answer is total squares (N^2) minus forbidden squares plus the pieces themselves (since they are already occupied)
    i64 answer = N * N - forbidden + M - pieces.size();
    // But since M pieces are already placed, the forbidden squares include them. So, adjust by subtracting M (as they were counted in forbidden)
    answer = N * N - forbidden;
    cout << answer << "\n";

    return 0;
}