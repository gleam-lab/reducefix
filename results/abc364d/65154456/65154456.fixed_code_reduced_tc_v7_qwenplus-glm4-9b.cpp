#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 200000 + 10; // Adjusted for the problem constraints
int a[MAXN];

int n, q;

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < q; j++) {
        int b, k;
        cin >> b >> k;
        // We use binary search to find the k-th closest point A_i to the point B_j
        int lo = 0, hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            // Check if the k-th closest point is in the range [mid, mid+1]
            if (mid < n && a[mid + 1] >= b && k <= mid) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        // Output the distance between the k-th closest A_i and B_j
        cout << abs(a[lo] - b) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1; // If multiple test cases are provided
    while (t--) {
        solve();
    }
    return 0;
}