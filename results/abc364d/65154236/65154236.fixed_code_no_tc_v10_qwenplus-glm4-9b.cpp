#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first -= a[0]; // Normalize to origin
    }
    
    // Sort queries based on the point B_j
    sort(queries.begin(), queries.end());
    
    // Process sorted queries
    for (auto& p : queries) {
        int b = p.first + a[0]; // Convert back to original coordinates
        int k = p.second - 1; // Convert to zero-indexed
        
        // Binary search to find the k-th closest point A_i to B_j
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (a[mid] <= b) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        
        // Calculate distance
        cout << abs(a[low] - b) << endl;
    }
    
    return 0;
}