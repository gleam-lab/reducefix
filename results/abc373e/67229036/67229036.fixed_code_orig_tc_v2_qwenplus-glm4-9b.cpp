#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k;
int a[N], b[N], c[N];
int ans[N];
int lower_bound(int *arr, int l, int r, int x) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

signed main() {
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    k -= a[0]; // Reduce the remaining votes by the votes already received by the leading candidate.
    sort(a + 1, a + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        b[i] = a[i];
        c[i] = sum;
    }

    for (int i = 0; i < n; i++) {
        if (i >= m) { // Only need to consider the leading candidates.
            int votes_needed = lower_bound(b + 1, b + n + 1, c[n] - c[n - m]) - c[n - m];
            if (votes_needed > k) {
                ans[i] = -1;
            } else {
                ans[i] = c[n] - c[n - m] - votes_needed;
            }
        } else {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}