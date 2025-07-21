#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> queries;
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }
    
    // Sort points A and queries by B to facilitate the distance calculations
    sort(a.begin(), a.end());
    sort(queries.begin(), queries.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    
    // Prepare to store the distances for each query
    vector<int> results(q);
    
    // To handle the distance calculations efficiently, we need to find the k-th smallest distance
    // for each point B_j using binary search
    for (int j = 0, k = 0; j < q; ++j) {
        int b = queries[j].first;
        int k_j = queries[j].second;
        
        // Binary search to find the k_j-th smallest distance between points A and B_j
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            int count = 0;
            for (int i = 1; i <= mid; ++i) {
                count += upper_bound(a.begin(), a.end(), b + a[i]) - lower_bound(a.begin(), a.end(), b - a[i]);
            }
            if (count < k_j) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        
        results[j] = a[low] - queries[j].first;
    }
    
    // Output the results for each query
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}