#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, q, cnt, ans;
int a[N], b[N], k[N];

// Function to calculate the minimum distance for each query
void solve() {
    // Sort the coordinates of points A
    sort(a + 1, a + n + 1);

    // Process each query
    for (int i = 0; i < q; ++i) {
        int x = b[i], k_val = k[i];
        int l = 0, r = 1e8;

        // Binary search to find the k-th closest point
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;

            // Count points within the range [x - mid, x + mid]
            for (int j = 1; j <= n; ++j) {
                if (abs(a[j] - x) <= mid) {
                    ++count;
                }
            }

            // Adjust binary search bounds based on the count
            if (count >= k_val) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // Output the result for the current query
        cout << l << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input values
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> k[i];

    // Solve the problem
    solve();

    return 0;
}