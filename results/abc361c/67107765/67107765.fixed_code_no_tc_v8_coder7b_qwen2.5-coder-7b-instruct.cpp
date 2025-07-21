#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    
    // Read input values into the vector
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    
    // Sort the array to easily find the smallest and largest elements after removal
    sort(num.begin(), num.end());
    
    // Calculate the minimum possible difference between the max and min values of B
    int result = INT_MAX;
    for(int i = 0; i <= n - k; ++i) {
        // The maximum value of B will be the last element in the subarray of size (n-k)
        // starting at index i
        int max_value = num[i + k - 1];
        
        // The minimum value of B will be the first element in the same subarray
        int min_value = num[i];
        
        // Update the result with the minimum difference found
        result = min(result, max_value - min_value);
    }
    
    // Print the final result
    cout << result << endl;
    
    return 0;
}