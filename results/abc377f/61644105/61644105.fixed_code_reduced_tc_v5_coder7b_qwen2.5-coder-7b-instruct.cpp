#include <bits/stdc++.h>

#define MAX_N ((int) 1e3)

#define abs(x) ((x) < 0 ? -(x) : (x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

long long n, m;

int rowN, colN, upN[2], downN[2];
long long row[MAX_N + 1], col[MAX_N + 1], up[2][MAX_N + 1], down[2][MAX_N + 1];

#define exist(begin, end, x) std::binary_search(begin, end, x)
#define existRow(x) exist(row + 1, row + rowN + 1, x)
#define existCol(x) exist(col + 1, col + colN + 1, x)
#define existUp(x) exist(up[x & 1] + 1, up[x & 1] + upN[x & 1] + 1, x)
#define existDown(x) exist(down[x & 1] + 1, down[x & 1] + downN[x & 1] + 1, x)

#define count(begin, end, l, r) (std::upper_bound(begin, end, r) - std::lower_bound(begin, end, l))
#define countUp(idx, l, r) count(up[idx] + 1, up[idx] + upN[idx] + 1, l, r)
#define countUpAll(l, r) (countUp(0, l, r) + countUp(1, l, r))
#define countDown(idx, l, r) count(down[idx] + 1, down[idx] + downN[idx] + 1, l, r)
#define countDownAll(l, r) (countDown(0, l, r) + countDown(1, l, r))

#define forRow(v) for (int i = 1, v = row[1]; i <= rowN; v = row[++i])
#define forCol(v) for (int i = 1, v = col[1]; i <= colN; v = col[++i])
#define forUp(v) for (int j = 0; j <= 1; j++) for (int i = 1, v = up[j][1]; i <= upN[j]; v = up[j][++i])
#define forDown(v) for (int j = 0; j <= 1; j++) for (int i = 1, v = down[j][1]; i <= downN[j]; v = down[j][++i])

long long ans;

int main() {
    scanf("%lld %lld", &m, &n);
    for (int i = 1; i <= m; i++) {
        long long x, y, d; scanf("%lld %lld", &x, &y); d = (x + y) & 1;
        row[i] = y, col[i] = x, up[d][++upN[d]] = y - x, down[d][++downN[d]] = x + y;
    }

    sort(row + 1, row + m + 1); rowN = unique(row + 1, row + m + 1) - row - 1;
    sort(col + 1, col + m + 1); colN = unique(col + 1, col + m + 1) - col - 1;
    sort(up[0] + 1, up[0] + upN[0] + 1); upN[0] = unique(up[0] + 1, up[0] + upN[0] + 1) - up[0] - 1;
    sort(up[1] + 1, up[1] + upN[1] + 1); upN[1] = unique(up[1] + 1, up[1] + upN[1] + 1) - up[1] - 1;
    sort(down[0] + 1, down[0] + downN[0] + 1); downN[0] = unique(down[0] + 1, down[0] + downN[0] + 1) - down[0] - 1;
    sort(down[1] + 1, down[1] + downN[1] + 1); downN[1] = unique(down[1] + 1, down[1] + downN[1] + 1) - down[1] - 1;

    // Calculate the total number of empty squares
    ans = n * n - m;

    // Subtract the squares that are captured
    forRow(v) {
        int cntUp = countUpAll(-v, 0) + countDownAll(n, n + v);
        int cntDown = countDownAll(-v, 0) + countUpAll(n, n + v);
        ans -= cntUp + cntDown;
    }
    forCol(v) {
        int cntUp = countUpAll(-v, 0) + countDownAll(n, n + v);
        int cntDown = countDownAll(-v, 0) + countUpAll(n, n + v);
        ans -= cntUp + cntDown;
    }

    printf("%lld\n", ans);
    return 0;
}