#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read array elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate the minimum difference between max and min values after removing K elements
    int minDiff = INT_MAX;
    for (int i = 0; i <= n - k; ++i) {
        minDiff = min(minDiff, a[i + k - 1] - a[i]);
    }
    
    // Output the result
    cout << minDiff << endl;
    
    return 0;
}