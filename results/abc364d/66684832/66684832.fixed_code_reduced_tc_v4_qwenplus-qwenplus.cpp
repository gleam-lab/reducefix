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

        // Binary search bounds
        int low = 0;
        int high = 2e14; // Large enough upper bound on max possible distance

        while (low < high) {
            int mid = (low + high) / 2;
            // Find first A[i] >= b - mid
            int left = lower_bound(a, a + n, b - mid) - a;
            // Find first A[i] > b + mid
            int right = lower_bound(a, a + n, b + mid + 1) - a;
            int count = right - left;

            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << endl;
    }

    return 0;
}