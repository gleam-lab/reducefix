#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to find the largest and smallest elements easily
    sort(a.begin(), a.end());
    
    // Calculate minimum and maximum possible values of B
    int min_possible_diff = INT_MAX;
    
    // Case 1: Remove K smallest elements
    if (k < n) {
        int max_val = a[k + n - 1];
        int min_val = a[k];
        min_possible_diff = min(min_possible_diff, max_val - min_val);
    }
    
    // Case 2: Remove K largest elements
    if (k < n) {
        int max_val = a[n - k - 1];
        int min_val = a[n - k];
        min_possible_diff = min(min_possible_diff, max_val - min_val);
    }
    
    // Case 3: Remove the K smallest and K largest elements (if k is even)
    if (k % 2 == 0) {
        int max_val = a[k + 1]; // K+1 because we are removing 2*k elements, thus the next element is the new max
        int min_val = a[n - k - 1]; // K-1 because we are removing 2*k elements, thus the K-1th element is the new min
        min_possible_diff = min(min_possible_diff, max_val - min_val);
    }
    
    cout << min_possible_diff << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}