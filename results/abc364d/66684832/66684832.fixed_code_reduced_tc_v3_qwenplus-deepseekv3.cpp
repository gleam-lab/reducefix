#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 10;
int a[N];

bool check(int p, int dx, int n, int k) {
    int left = lower_bound(a + 1, a + n + 1, p - dx) - a;
    int right = upper_bound(a + 1, a + n + 1, p + dx) - a;
    return (right - left) >= k;
}

int findans(int pos, int k, int n) {
    int l = 0, r = 2e14;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(pos, mid, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k, n) << endl;
    }

    return 0;
}