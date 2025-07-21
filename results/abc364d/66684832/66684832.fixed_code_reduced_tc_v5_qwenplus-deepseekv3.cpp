#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 10;

int a[N];

bool check(int pos, int dx, int k, int n) {
    int left = lower_bound(a, a + n, pos - dx) - a;
    int right = upper_bound(a, a + n, pos + dx) - a;
    return (right - left) >= k;
}

int findans(int pos, int k, int n) {
    int l = 0, r = 2e14; // Sufficiently large to cover all possible distances
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(pos, mid, k, n)) {
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k, n) << '\n';
    }

    return 0;
}