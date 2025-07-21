#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum possible value of the difference between the maximum and minimum values of the resulting sequence
long long minDiff(long long n, long long k, vector<long long>& arr) {
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Initialize the result with a large number
    long long res = LLONG_MAX;
    
    // Iterate through the array and consider each possible subarray after removing k elements
    for(long long i = 0; i <= n - k; ++i) {
        // Calculate the difference between the maximum and minimum values of the current subarray
        long long diff = arr[i + k - 1] - arr[i];
        
        // Update the result with the minimum difference found so far
        res = min(res, diff);
    }
    
    return res;
}

int main() {
    long long n, k;
    cin >> n >> k;
    
    vector<long long> arr(n);
    for(long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Call the function to find the minimum possible value of the difference
    long long ans = minDiff(n, k, arr);
    
    // Print the result
    cout << ans << endl;
    
    return 0;
}