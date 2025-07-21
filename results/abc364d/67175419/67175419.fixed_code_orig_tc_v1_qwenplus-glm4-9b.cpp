#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MAXDist = 1e8 + 5; // Using a large constant as a distance bound
int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        // Calculate the range of distances for the binary search
        int l = -MAXDist, r = MAXDist;
        while (r - l > 1) { // Ensure we go through the loop at least once
            int mid = (l + r) / 2;
            int count = 0;
            // Count how many points A are within distance `mid` of point B
            for (int j = 1; j <= n; j++) {
                count += abs(a[j] - b) <= mid;
            }
            if (count >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // Now l is the largest value such that there are at least k points in the range [l, l + x)
        // The k-th closest point distance is `l` or `l + 1`, depending on the count
        cout << r << "\n"; // This will print the correct distance
    }
    return 0;
}