#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010; // large enough to store all points
int a[MAXN], cnt[MAXN];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        // Shift the coordinate to be centered around 0
        ++cnt[min(MAXN / 2, max(0, x + MAXN / 2))];
    }

    for (int i = 1; i < MAXN; ++i) {
        // Cumulative sum to get the count of points up to index i
        cnt[i] += cnt[i - 1];
    }

    while (q--) {
        int x, k; scanf("%d %d", &x, &k);
        // Get the distance for the k-th closest point
        int dist = upper_bound(cnt, cnt + MAXN, k) - cnt;
        // Shift it back to the original coordinate system
        printf("%ld\n", (long long)dist * 5 - 2 * MAXN);
    }
    
    return 0;
}