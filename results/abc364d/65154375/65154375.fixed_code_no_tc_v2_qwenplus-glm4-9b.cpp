#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN]; // Store the count of each point

int main() {
    int n, q;
    cin >> n >> q;
    // Initialize array a with 0
    memset(a, 0, sizeof(a));

    // Read points A_i and increment their count in array a
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x + MAXN / 2]++; // Shift x to the middle of the array to handle negative x
    }

    // Compute prefix sums to make array a represent the number of points up to each point
    for (int i = 1; i < MAXN; ++i) {
        a[i] += a[i - 1];
    }

    // Process each query
    while (q--) {
        int x, k;
        cin >> x >> k;
        // Search for the k-th closest point to B_j (x)
        // Binary search between -MAXN/2 and MAXN/2 to find the k-th closest point
        int l = -MAXN / 2, r = MAXN / 2;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            // Check if we are within the range by ensuring the count of points to the left and right
            // of mid is sufficient
            if (x - mid >= 0 && a[min(MAXN / 2, x + mid)] - a[max(0, x - mid - 1)] >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // Output the distance from the k-th closest point to B_j (x)
        cout << abs(x - l) << endl;
    }

    return 0;
}