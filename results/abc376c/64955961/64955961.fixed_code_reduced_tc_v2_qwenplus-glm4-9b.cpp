#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];

    // Sort the toy sizes and box sizes to facilitate the comparison
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We need to find the smallest box size that can accommodate all toys
    // Starting from the smallest needed size to the largest, we check if it can fit all toys
    int left = 1, right = a[n - 1];  // The smallest size that can fit the largest toy is at least 1
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool valid = false;
        // Check if this box size can fit all toys
        for (int i = 0; i < n && a[i] <= mid; i++) {
            // Find the first box that is larger than the current toy size
            int lo = 0, hi = n - 2;
            while (lo < hi) {
                int mi = lo + (hi - lo + 1) / 2;
                if (b[mi] < a[i]) lo = mi;
                else hi = mi - 1;
            }
            // If the last box checked is still not larger, it means all remaining boxes can fit this toy
            if (b[hi] < a[i]) {
                valid = true;
                break;
            }
        }
        // If the mid size is a valid box size, try a smaller size
        if (valid) {
            right = mid - 1;
            ans = mid;
        } else {
            left = mid + 1;
        }
    }
    // Output the smallest valid box size, or -1 if no such size exists
    cout << ans << endl;
    return 0;
}

int main() {
    solve();
    return 0;
}