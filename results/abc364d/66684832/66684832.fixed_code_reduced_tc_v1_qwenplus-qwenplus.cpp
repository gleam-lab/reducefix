#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e5 + 9;

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

        // Binary search boundaries
        int low = 0, high = 1e18;
        while (low < high) {
            int mid = (low + high) / 2;

            // Two pointers to count how many distances <= mid
            int left = 0, right = 0;
            int count = 0;

            // Sliding window to find number of elements in [b - mid, b + mid]
            while (right < n) {
                while (left < right && abs(b - a[right]) + abs(a[right] - a[left]) <= mid) {
                    ++right;
                }
                count += right - left;
                ++right;
            }

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