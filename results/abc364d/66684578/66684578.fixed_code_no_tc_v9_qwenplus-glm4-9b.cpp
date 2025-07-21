#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>

int main() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];

    while (q--) {
        int b, k;
        cin >> b >> k;
        // Find the k-th closest point A_i to B_j
        // We need to find a position on the line such that the distance
        // to B_j is the k-th smallest distance from A_i.
        // Binary search for the position
        int left = 0, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            // Calculate distances from A_i to B_j
            ll dist_left = absll(a[mid] - b);
            ll dist_right = absll(a[mid + 1] - b);
            // Check if k-th closest point is closer to the left or right
            if (k <= dist_left - dist_right) {
                right = mid;
            } else {
                left = mid;
            }
        }
        // Output the result
        cout << min(absll(a[left] - b), absll(a[left + 1] - b)) << endl;
    }
    return 0;
}