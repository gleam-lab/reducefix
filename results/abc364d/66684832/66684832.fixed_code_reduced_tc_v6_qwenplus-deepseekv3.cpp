#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

bool check(int pos, int d, int n, int k) {
    int left = lower_bound(a, a + n, pos - d) - a;
    int right = upper_bound(a, a + n, pos + d) - a;
    return (right - left) >= k;
}

int findans(int pos, int k, int n) {
    int l = 0, r = 2e18;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
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
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << findans(b, k, n) << '\n';
    }

    return 0;
}