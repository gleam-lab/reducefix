#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 10;
int n, m;
int row[MAX_N], col[MAX_N];
int up[2][MAX_N], down[2][MAX_N];
int rowN, colN, upN[2], downN[2];

bool exists(int arr[], int len, int val) {
    return binary_search(arr, arr + len, val);
}

int countInRange(int arr[], int len, int l, int r) {
    return upper_bound(arr, arr + len, r) - lower_bound(arr, arr + len, l);
}

void update(int arr[], int& len, int val) {
    int pos = upper_bound(arr, arr + len, val) - arr;
    arr[pos] = val;
    while (pos > 0 && arr[pos] < arr[pos - 1]) {
        swap(arr[pos], arr[--pos]);
    }
    ++len;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        int d = (x + y) & 1;
        update(row, rowN, y);
        update(col, colN, x);
        update(up[d], upN[d], y - x);
        update(down[d], downN[d], x + y);
    }

    sort(row, row + rowN);
    sort(col, col + colN);
    sort(up[0], up[0] + upN[0]);
    sort(up[1], up[1] + upN[1]);
    sort(down[0], down[0] + downN[0]);
    sort(down[1], down[1] + downN[1]);

    long long ans = (long long)n * n - m;
    for (int i = 0; i < rowN; ++i) {
        ans -= countInRange(up[0], upN[0], 1, row[i] - 1);
        ans -= countInRange(up[1], upN[1], row[i] + 1, n);
        ans -= countInRange(down[0], downN[0], 1, row[i] - 1);
        ans -= countInRange(down[1], downN[1], row[i] + 1, n);
    }
    for (int i = 0; i < colN; ++i) {
        ans -= countInRange(up[0], upN[0], 1, col[i] - 1);
        ans -= countInRange(up[1], upN[1], col[i] + 1, n);
        ans -= countInRange(down[0], downN[0], 1, col[i] - 1);
        ans -= countInRange(down[1], downN[1], col[i] + 1, n);
    }
    for (int i = 0; i < upN[0]; ++i) {
        for (int j = 0; j < upN[1]; ++j) {
            ans -= exists(row, rowN, up[0][i] + up[1][j]);
            ans -= exists(row, rowN, up[1][j] - up[0][i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}