#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], c[N];

bool check(int val, int x) {
    int total_votes = val + x;
    int pos = upper_bound(b + 1, b + n + 1, total_votes) - b - 1;
    int rank = n - pos;
    if (rank < m) {
        return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    int remaining = k - sum;
    for (int i = 1; i <= n; ++i) {
        int low = 0, high = remaining;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(a[i], mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << " ";
    }
    return 0;
}