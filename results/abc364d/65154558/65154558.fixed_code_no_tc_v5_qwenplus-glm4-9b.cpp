#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 100000 + 5;  // Adjusted for range of a_i and b_j
int a[MAXN];  // Using a large enough array to avoid index errors

// Function to sort and process each query
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x + 100000000]++;  // We use x + 100000000 to avoid negative indices
    }

    // Build prefix sum array to count the number of elements up to each index
    for (int i = 1; i < MAXN; i++) {
        a[i] += a[i - 1];
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        int l = 0, r = n;
        // Binary search for the k-th closest point to b_j
        while (r - l > 1) {
            int mid = (l + r) / 2;
            // Check if the k-th closest point is at or before the mid index
            if (a[mid] - a[max(0, x - 100000001 + mid)] >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // Output the distance to the k-th closest point
        cout << abs(x - (r - 100000000)) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}