#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3;

int n, m;
int rowN, colN, upN[2], downN[2];
int row[MAX_N + 1], col[MAX_N + 1], up[2][MAX_N + 1], down[2][MAX_N + 1];

bool exist(int begin, int end, int x) {
    return binary_search(begin, end, x);
}

bool existRow(int x) {
    return exist(row + 1, row + rowN + 1, x);
}

bool existCol(int x) {
    return exist(col + 1, col + colN + 1, x);
}

bool existUp(int x) {
    return exist(up[x & 1] + 1, up[x & 1] + upN[x & 1] + 1, x);
}

bool existDown(int x) {
    return exist(down[x & 1] + 1, down[x & 1] + downN[x & 1] + 1, x);
}

int count(int begin, int end, int l, int r) {
    return upper_bound(begin, end, r) - lower_bound(begin, end, l);
}

int countUp(int idx, int l, int r) {
    return count(up[idx] + 1, up[idx] + upN[idx] + 1, l, r);
}

int countUpAll(int l, int r) {
    return countUp(0, l, r) + countUp(1, l, r);
}

int countDown(int idx, int l, int r) {
    return count(down[idx] + 1, down[idx] + downN[idx] + 1, l, r);
}

int countDownAll(int l, int r) {
    return countDown(0, l, r) + countDown(1, l, r);
}

void process() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, d; scanf("%d %d", &x, &y); d = (x + y) & 1;
        row[i] = y, col[i] = x, up[d][++upN[d]] = y - x, down[d][++downN[d]] = x + y;
    }

    sort(row + 1, row + m + 1); rowN = unique(row + 1, row + m + 1) - row - 1;
    sort(col + 1, col + m + 1); colN = unique(col + 1, col + m + 1) - col - 1;
    sort(up[0] + 1, up[0] + upN[0] + 1); upN[0] = unique(up[0] + 1, up[0] + upN[0] + 1) - up[0] - 1;
    sort(up[1] + 1, up[1] + upN[1] + 1); upN[1] = unique(up[1] + 1, up[1] + upN[1] + 1) - up[1] - 1;
    sort(down[0] + 1, down[0] + downN[0] + 1); downN[0] = unique(down[0] + 1, down[0] + downN[0] + 1) - down[0] - 1;
    sort(down[1] + 1, down[1] + downN[1] + 1); downN[1] = unique(down[1] + 1, down[1] + downN[1] + 1) - down[1] - 1;

    long long ans = (long long) m * m; // Total squares initially

    // Subtract squares that can be captured by rows and columns
    ans -= (long long) m * (rowN + colN);

    // Subtract squares that can be captured by diagonals
    for (int v : up[0]) ans -= m - abs(v);
    for (int v : up[1]) ans -= m - abs(m + 1 - v);
    for (int v : down[0]) ans -= m - abs(v);
    for (int v : down[1]) ans -= m - abs(m + 1 - v);

    // Add back squares that are counted twice (intersection of rows and columns with diagonals)
    ans += rowN * colN;
    for (int v : row) ans += countUpAll(v - m, v - 1) + countDownAll(v + 1, v + m);
    for (int v : col) ans += countUpAll(1 - v, m - v) + countDownAll(v + 1, v + m);
    for (int d = 0; d <= 1; d++) ans += countDown(d & 1, max(2 - d, 2 + d), min(2 * m - d, 2 * m + d));

    // Subtract squares that are captured by both row and diagonal
    for (int y : row) for (int x : col) ans -= existUp(y - x) + existDown(x + y);

    // Add back squares that are captured by both column and diagonal
    for (int d = 0; d <= 1; d++) for (int s = 0; s <= 1; s++) if (~(d ^ s) & 1) {
        int x = (s - d) >> 1, y = (d + s) >> 1;
        if (1 <= x && x <= m && 1 <= y && y <= m) ans -= existRow(y) + existCol(x);
    }

    // Subtract squares that are captured by all four directions
    for (int y : row) for (int x : col) ans += (existUp(y - x) & existDown(x + y));

    printf("%lld\n", ans);
}

int main() {
    process();
    return 0;
}