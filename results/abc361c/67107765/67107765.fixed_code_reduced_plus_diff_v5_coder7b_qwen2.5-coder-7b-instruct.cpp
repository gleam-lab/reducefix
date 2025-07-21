#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    // Sort the array to facilitate easy removal of smallest and largest elements
    sort(arr.begin(), arr.end());

    // The optimal strategy is to always remove the smallest k/2 elements 
    // and the largest k/2 elements, because removing the middle elements would increase the range.
    long long min_val = arr[k/2]; // Minimum value after removal
    long long max_val = arr[n-k/2-1]; // Maximum value after removal
    
    // Calculate the difference between max and min values
    long long result = max_val - min_val;
    
    cout << result << '\n';
    
    return 0;
}