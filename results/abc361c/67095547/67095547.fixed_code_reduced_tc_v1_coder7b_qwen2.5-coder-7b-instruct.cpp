#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to easily find the minimum and maximum values
    sort(a.begin(), a.end());
    
    // Initialize the result with the initial difference
    long long min_diff = a.back() - a.front();
    
    // Iterate over possible positions to split the array into two parts
    for (int i = 0; i <= k; ++i) {
        // Calculate the maximum value of the remaining part
        long long max_val = max(a[k - i], a[n - 1]);
        
        // Calculate the minimum value of the remaining part
        long long min_val = min(a[i], a[n - k + i - 1]);
        
        // Update the minimum difference
        min_diff = min(min_diff, max_val - min_val);
    }
    
    cout << min_diff << endl;
    
    return 0;
}