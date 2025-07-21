#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the input array
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Edge case for when k is greater than the array size
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }
    
    long long min_diff = LLONG_MAX;
    
    // Iterate over all possible starting points of the subsequence of length k
    for (int i = 0; i <= n - k; i++) {
        // Extract the subsequence of length k
        int max_val = a[i + k - 1];
        int min_val = a[i];
        
        // Calculate the difference between the max and min of the subsequence
        long long diff = max_val - min_val;
        
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}