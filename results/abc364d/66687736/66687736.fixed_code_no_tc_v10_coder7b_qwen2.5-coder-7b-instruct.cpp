#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    vector<pair<int, int>> queries(q);
    
    // Read coordinates of points A_i
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read coordinates of points B_j and their corresponding k_j
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    // Sort points A_i to facilitate binary search
    sort(a.begin(), a.end());
    
    // Process each query
    for(const auto& query : queries) {
        int b = query.first;
        int k = query.second;
        
        // Binary search to find the k-th closest point to B_j
        int left = 0, right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int dist = abs(a[mid] - b);
            
            if(mid >= k - 1 && (mid == 0 || dist <= abs(a[mid - 1] - b))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Output the distance
        cout << abs(a[left] - b) << '\n';
    }
    
    return 0;
}