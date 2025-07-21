#include <bits/stdc++.h>
using namespace std;

#define MAX_N ((int)1e3)

int n, m, a[MAX_N + 1], b[MAX_N + 1];

bool canPlace(int r, int c) {
    for (int i = 0; i < m; ++i) {
        if (a[i] == r || b[i] == c || a[i] + b[i] == r + c || a[i] - b[i] == r - c) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a[i], &b[i]);
    }

    long long emptyCount = 0;
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            if (canPlace(r, c)) {
                emptyCount++;
            }
        }
    }

    printf("%lld\n", emptyCount);
    return 0;
}