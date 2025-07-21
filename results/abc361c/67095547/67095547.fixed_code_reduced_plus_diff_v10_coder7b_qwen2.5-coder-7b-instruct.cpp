#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the minimum difference between the maximum and minimum values
int minDifference(vector<int>& arr, int k) {
    // Sort the array
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int res = arr[n-1] - arr[0]; // Initial result with removing no elements
    
    // Try removing each element one by one and update the result
    for (int i = 0; i <= n-k; ++i) {
        res = min(res, arr[i+k-1] - arr[i]);
    }
    
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Calculate and print the result
    cout << minDifference(arr, k) << endl;
    
    return 0;
}