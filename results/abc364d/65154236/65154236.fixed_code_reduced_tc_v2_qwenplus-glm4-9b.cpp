#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        int lb = 0, ub = n;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            int dist = abs(a[mid] - b);
            if (mid > 0) dist = max(dist, abs(a[mid - 1] - b));
            if (mid < n - 1) dist = max(dist, abs(a[mid + 1] - b));
            
            if (dist < k) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        
        // Calculate the k-th closest distance
        int kth_closest_dist = abs(a[lb] - b);
        if (lb > 0) kth_closest_dist = max(kth_closest_dist, abs(a[lb - 1] - b));
        if (lb < n - 1) kth_closest_dist = max(kth_closest_dist, abs(a[lb + 1] - b));
        
        // If k is not in the exact position, we need to consider the next closest point
        if (kth_closest_dist < k) {
            // Find the closest point after the one found
            int next_closest = lb;
            while (next_closest < n - 1 && abs(a[next_closest + 1] - b) == kth_closest_dist) {
                next_closest++;
            }
            cout << abs(a[next_closest] - b) << endl;
        } else {
            cout << kth_closest_dist << endl;
        }
    }

    return 0;
}