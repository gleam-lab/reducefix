#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), b(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i];
    
    // Sort the points
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i = 0; i < q; ++i) {
        int target = b[i];
        int k = i + 1; // Convert to 0-based index
        
        // Binary search for the k-th smallest distance
        int left = 0, right = 2 * 1e8; // Upper bound for the maximum distance
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // Count how many points are within distance mid of target
            for (int x : a) {
                if (abs(x - target) <= mid) {
                    count++;
                }
            }
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
    
    return 0;
}