#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search bounds based on maximum possible distance
        int low = 0, high = 2e8;
        int answer = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            // Find first index where a[i] >= b - mid
            int left = lower_bound(a, a + n, b - mid) - a;
            // Find first index where a[i] > b + mid
            int right = upper_bound(a, a + n, b + mid) - a;
            int count = right - left;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}