#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the elements into the vector
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the vector
    sort(a.begin(), a.end());
    
    // Initialize the maximum difference to a large value
    long long min_diff = LLONG_MAX;
    
    // Iterate over all possible starting points of the window of size k
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the max and min of the current window
        long long current_diff = a[i + k - 1] - a[i];
        
        // Update the minimum difference found so far
        min_diff = min(min_diff, current_diff);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}