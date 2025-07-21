// LUOGU_RID: 197922896
#include <bits/stdc++.h>

#define MAX_N ((int) 1e3)

#define abs(x) ((x) < 0 ? -(x) : (x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m;

int rowN, colN, upN[2], downN[2];
int row[MAX_N + 1], col[MAX_N + 1], up[2][MAX_N + 1], down[2][MAX_N + 1];

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
#define forCol(v) for (int i = 1, v = row[1]; i <= colN; v = col[++i])
#define forUp(v) for (int j = 0; j <= 1; j++) for (int i = 1, v = up[j][1]; i <= upN[j]; v = up[j][++i])
#define forDown(v) for (int j = 0; j <= 1; j++) for (int i = 1, v = down[j][1]; i <= downN[j]; v = down[j][++i])

long long ans;

main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		int x, y, d; scanf("%d %d", &x, &y); d = (x + y) & 1;
		row[i] = y, col[i] = x, up[d][++upN[d]] = y - x, down[d][++downN[d]] = x + y;
	}

	std::sort(row + 1, row + n + 1); rowN = std::unique(row + 1, row + n + 1) - row - 1;
	std::sort(col + 1, col + n + 1); colN = std::unique(col + 1, col + n + 1) - col - 1;
	std::sort(up[0] + 1, up[0] + upN[0] + 1); upN[0] = std::unique(up[0] + 1, up[0] + upN[0] + 1) - up[0] - 1;
	std::sort(up[1] + 1, up[1] + upN[1] + 1); upN[1] = std::unique(up[1] + 1, up[1] + upN[1] + 1) - up[1] - 1;
	std::sort(down[0] + 1, down[0] + downN[0] + 1); downN[0] = std::unique(down[0] + 1, down[0] + downN[0] + 1) - down[0] - 1;
	std::sort(down[1] + 1, down[1] + downN[1] + 1); downN[1] = std::unique(down[1] + 1, down[1] + downN[1] + 1) - down[1] - 1;

// Zero:
	ans = (long long) m * m; // NULL
// One:
	ans -= (long long) m * (rowN + colN); // ROW, COL
	forUp(v) ans -= m - abs(v); // UP
	forDown(v) ans -= m - abs(m + 1 - v); // DOWN
// Two:
	ans += rowN * colN; // ROW & COL
	forRow(v) ans += countUpAll(v - m, v - 1) + countDownAll(v + 1, v + m); // ROW & UP, ROW & DOWN
	forCol(v) ans += countUpAll(1 - v, m - v) + countDownAll(v + 1, v + m); // COL & UP, COL & DOWN
	forUp(d) ans += countDown(d & 1, max(2 - d, 2 + d), min(2 * m - d, 2 * m + d)); // UP & DOWN
// Three:
	forRow(y) forCol(x) ans -= existUp(y - x) + existDown(x + y); // ROW & COL & UP, ROW & COL & DOWN
	forUp(d) forDown(s) if (~(d ^ s) & 1) { // ROW & UP & DOWN, COL & UP & DOWN
		int x = (s - d) >> 1, y = (d + s) >> 1;
		if (1 <= x && x <= m && 1 <= y && y <= m) ans -= existRow(y) + existCol(x);
	}
// FOUR:
	forRow(y) forCol(x) ans += (existUp(y - x) & existDown(x + y)); // ROW & COL & UP & DOWN

	printf("%lld\n", ans);
	return 0;
}
