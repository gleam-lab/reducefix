#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    vector<pair<int, int>> queries(q);
    
    // Read coordinates of points A
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read queries
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].second; // Convert to zero-based index
    }
    
    // Sort points A
    sort(a.begin(), a.end());
    
    // Process each query
    for(auto& [b, k] : queries) {
        int pos = upper_bound(a.begin(), a.end(), b) - a.begin();
        
        // If k-th element is within the array bounds
        if(k < pos && k >= 0) {
            int leftDist = abs(a[k] - b);
            int rightDist = (pos == n ? MAX : abs(a[pos] - b));
            
            // Determine the k-th smallest distance
            if(leftDist <= rightDist) {
                cout << leftDist << '\n';
            } else {
                cout << rightDist << '\n';
            }
        } else {
            // Handle edge cases where k is out of bounds
            cout << "0\n";
        }
    }

    return 0;
}