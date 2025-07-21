#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, m;
int rowN, colN, upN[2], downN[2];
int row[MAXN], col[MAXN], up[2][MAXN], down[2][MAXN];

bool exist(int begin, int end, int x) {
    return lower_bound(begin, end, x) != end && *lower_bound(begin, end, x) == x;
}

bool existRow(int x) {
    return exist(row, row + rowN, x);
}

bool existCol(int x) {
    return exist(col, col + colN, x);
}

bool existUp(int x) {
    return exist(up[0], up[0] + upN[0], x) || exist(up[1], up[1] + upN[1], x);
}

bool existDown(int x) {
    return exist(down[0], down[0] + downN[0], x) || exist(down[1], down[1] + downN[1], x);
}

int count(int begin, int end, int l, int r) {
    return upper_bound(begin, end, r) - lower_bound(begin, end, l);
}

int countUp(int idx, int l, int r) {
    return count(up[idx], up[idx] + upN[idx], l, r);
}

int countUpAll(int l, int r) {
    return countUp(0, l, r) + countUp(1, l, r);
}

int countDown(int idx, int l, int r) {
    return count(down[idx], down[idx] + downN[idx], l, r);
}

int countDownAll(int l, int r) {
    return countDown(0, l, r) + countDown(1, l, r);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int d = (x + y) & 1;
        row[rowN++] = y;
        col[colN++] = x;
        up[d][upN[d]++] = y - x;
        down[d][downN[d]++] = x + y;
    }
    
    sort(row, row + rowN);
    sort(col, col + colN);
    sort(up[0], up[0] + upN[0]);
    sort(up[1], up[1] + upN[1]);
    sort(down[0], down[0] + downN[0]);
    sort(down[1], down[1] + downN[1]);

    int ans = m * m;
    ans -= m * (rowN + colN);

    for (int i = 0; i < rowN; ++i) {
        ans -= m - abs(row[i]);
    }

    for (int i = 0; i < colN; ++i) {
        ans -= m - abs(col[i]);
    }

    for (int i = 0; i < upN[0]; ++i) {
        ans -= m - abs(up[0][i]);
    }

    for (int i = 0; i < upN[1]; ++i) {
        ans -= m - abs(up[1][i]);
    }

    for (int i = 0; i < downN[0]; ++i) {
        ans -= m - abs(down[0][i]);
    }

    for (int i = 0; i < downN[1]; ++i) {
        ans -= m - abs(down[1][i]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}