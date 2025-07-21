#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum experience points
long long maxExperience(const vector<int>& a) {
    int n = a.size();
    
    // Edge case: If there's only one element, return it directly
    if (n == 1) return a[0];
    
    // Initialize DP arrays
    vector<long long> dp_odd(n, 0), dp_even(n, 0);
    dp_odd[0] = a[0];
    dp_even[0] = 0;
    dp_odd[1] = a[1];
    dp_even[1] = a[0] + 2 * a[1];
    
    // Fill the DP tables
    for (int i = 2; i < n; ++i) {
        dp_odd[i] = max(dp_odd[i-2] + 2LL * a[i], dp_even[i-1] + a[i]);
        dp_even[i] = max(dp_even[i-2] + a[i], dp_odd[i-1] + 2LL * a[i]);
    }
    
    // Return the maximum value between odd and even indexed endings
    return max(dp_odd[n-1], dp_even[n-1]);
}

// Main function to read input and output results
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // Calculate and print the result
    cout << maxExperience(a) << endl;
    
    return 0;
}