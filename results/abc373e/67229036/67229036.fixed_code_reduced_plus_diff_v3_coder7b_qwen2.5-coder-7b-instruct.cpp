#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long n, m, k, sum, cnt, a[N], b[N], c[N];

bool check(long long x, long long y) {
    int z = lower_bound(b + 1, b + 1 + n, x + y + 1) - b - 1;
    if (z < n - m)
        return false;
    return (x + y + 1) * (z - n + m) - (c[z] - c[n - m - 1] - max(x, b[n - m])) > k - y;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    for (i = 1; i <= n; ++i)
        cin >> a[i], k -= a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (i = 1; i <= n; ++i)
        c[i] = c[i - 1] + b[i];
    vector<long long> res(n);
    for (i = 1; i <= n; ++i) {
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(a[i], mid))
                r = mid;
            else
                l = mid + 1;
        }
        if (l <= k)
            res[i - 1] = l;
        else
            res[i - 1] = -1;
    }
    for (auto x : res)
        cout << x << " ";
    return 0;
}