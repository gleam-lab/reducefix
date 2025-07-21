#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 9;

int n, q;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on distance
        int lo = 0, hi = 2e14; // Safe upper bound based on input constraints

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // Find first index where |a[i] - b| > mid
            int l = lower_bound(a, a + n, b - mid) - a;
            int r = upper_bound(a, a + n, b + mid) - a;
            if (r - l >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << lo << endl;
    }

    return 0;
}