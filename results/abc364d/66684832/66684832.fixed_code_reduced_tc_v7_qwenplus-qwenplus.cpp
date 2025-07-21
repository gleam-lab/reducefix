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
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on the distance
        int left = 0, right = 2e8;
        int answer = right;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Find first index >= b - mid
            int* lo = lower_bound(a, a + n, b - mid);
            // Find first index > b + mid
            int* hi = upper_bound(a, a + n, b + mid);

            int count = hi - lo;

            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}