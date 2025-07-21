#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int j = 0; j < q; j++) {
        int b, k;
        cin >> b >> k;
        auto it = lower_bound(a.begin(), a.end(), b) - a.begin();
        int left = max(0, it - k);
        int right = min(n, it);
        
        // Binary search for the k-th closest point
        int ans = 0;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int dist1 = abs(a[mid] - b);
            int dist2 = abs(a[mid + 1] - b);
            if (dist1 <= dist2) {
                ans = dist1;
                right = mid;
            } else {
                ans = dist2;
                left = mid + 1;
            }
        }
        
        cout << min(ans, abs(a[left] - b)) << endl;
    }
    
    return 0;
}