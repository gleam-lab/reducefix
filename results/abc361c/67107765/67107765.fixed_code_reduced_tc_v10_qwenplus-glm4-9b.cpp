#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // Initialize the minimum difference to a very large value
    long long min_diff = LLONG_MAX;
    
    // Iterate over all possible windows of size k
    for (int i = 0; i <= n - k; ++i) {
        long long max_val = 0;
        long long min_val = LLONG_MAX;
        
        // Iterate over the window of size k
        for (int j = i; j < i + k; ++j) {
            max_val = max(max_val, a[j]);
            min_val = min(min_val, a[j]);
        }
        
        // Update the minimum difference
        min_diff = min(min_diff, max_val - min_val);
    }
    
    // Output the minimum difference found
    cout << min_diff << endl;
    
    return 0;
}