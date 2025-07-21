#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // If removing all elements except the first would result in a better solution,
    // then we only need to consider the elements to be removed to be the smallest K elements
    if (k == n - 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Initialize the minimum possible difference
    int min_diff = INT_MAX;
    
    // Use a sliding window of size K to find the minimum difference
    for (int i = 0; i <= n - k; i++) {
        // Calculate the maximum and minimum of the remaining elements after removing K elements
        int max_b = *max_element(a.begin() + i + k, a.end());
        int min_b = *min_element(a.begin() + i, a.begin() + i + k);
        
        // Update the minimum possible difference
        min_diff = min(min_diff, max_b - min_b);
    }
    
    cout << min_diff << endl;
    return 0;
}