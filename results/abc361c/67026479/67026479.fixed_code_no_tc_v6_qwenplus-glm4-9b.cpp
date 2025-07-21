#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Read the array elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Edge case when all elements need to be removed
    if (k == n) {
        cout << 0 << endl;
        return 0;
    }
    
    // Sort the array to easily find the minimum and maximum
    sort(a.begin(), a.end());
    
    // Calculate the minimum possible value of the maximum minus the minimum
    int result = a[n - k - 1] - a[k]; // This is the max of the remaining k elements
    result = min(result, a[n - 1] - a[k - 1]); // This is the max of the remaining n-k elements
    
    cout << result << endl;
    return 0;
}