#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sort the array to easily find the minimum and maximum values
    sort(arr.begin(), arr.end());

    // Initialize the result with a large number
    int result = INT_MAX;

    // Iterate through all possible pairs of indices (i, j) where i + j = k
    for(int i = 0; i <= k; ++i) {
        // Calculate the difference between the maximum and minimum values
        // After removing i smallest and k-i largest elements
        result = min(result, arr[k - i] - arr[i]);
    }

    // Print the final result
    cout << result << '\n';

    return 0;
}