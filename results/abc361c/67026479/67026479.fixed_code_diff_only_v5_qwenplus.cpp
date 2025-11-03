#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int m = n - k; // length of the remaining sequence
    
    // We need to choose a contiguous subarray of length m in the sorted array
    // because to minimize (max - min), we want the values to be as close as possible
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++) {
        int diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    return 0;
}