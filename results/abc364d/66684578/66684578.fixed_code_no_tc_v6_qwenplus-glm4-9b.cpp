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
        int b, k;
        cin >> b >> k;
        queries[i] = {b, k};
    }
    
    // Sort the points A and queries based on the points B
    sort(a.begin(), a.end());
    sort(queries.begin(), queries.end());
    
    vector<int> results(q);
    int j = 0;
    
    // Process each query
    for (const auto& p : queries) {
        int b = p.first;
        int k = p.second;
        
        // Find the k-th closest A to B
        while (j < n && a[j] < b) {
            j++;
        }
        
        if (j == 0) j++; // There is at least one point in A, so skip j == 0
        if (j == n) {
            results[k-1] = (b - a[n-1]);
        } else {
            results[k-1] = min(abs(b - a[j-1]), abs(b - a[j]));
        }
    }
    
    // Output the results for each query
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}