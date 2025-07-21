#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    
    // Reading the points A_i
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Vector to store the queries
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sort queries by the point B_j to optimize the distance calculation
    sort(queries.begin(), queries.end());
    
    // Vector to store the results
    vector<int> results(q);
    
    // Calculate distances for each query
    for (int i = 0; i < q; i++) {
        int b = queries[i].first;
        int k = queries[i].second;
        
        // Find the k-th closest point A_i to B_j
        // binary_search is used to find the first index that is >= k
        int idx = upper_bound(a.begin(), a.end(), b - 100000000) - a.begin();
        if (idx == 0) {
            // If k is 1, the closest point is A_0 with index -1
            results[i] = abs(a[0] - b);
        } else if (idx == n) {
            // If k is N, the closest point is A_n with index a_n - b
            results[i] = abs(a[n - 1] - b);
        } else {
            // Otherwise, it's the k-th closest point
            results[i] = abs(a[idx - 1] - b);
        }
    }
    
    // Output results
    for (int i = 0; i < q; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
}