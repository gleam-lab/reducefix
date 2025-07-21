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
    
    // Sort the array to facilitate the sliding window technique
    sort(a.begin(), a.end());
    
    long long min_diff = LLONG_MAX;
    
    // Iterate over all possible starting points of the window of size N-K
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum in the current window
        long long diff = a[i + k - 1] - a[i];
        // Update the minimum difference found so far
        min_diff = min(min_diff, diff);
    }
    
    // Output the minimum difference
    cout << min_diff << endl;
    
    return 0;
}