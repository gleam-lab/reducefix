#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We need to consider removing elements from both ends of the array.
    // We calculate the difference in two scenarios:
    // 1. Removing from the beginning and removing from the end.
    // 2. Removing from the middle (if K is odd).
    
    double min_diff = numeric_limits<double>::max();
    double max_val, min_val;
    
    // Case 1: Remove K elements from the beginning
    max_val = a[k-1];
    min_val = a[n-k];
    min_diff = min(min_diff, max_val - min_val);
    
    // Case 2: Remove K elements from the end
    max_val = a[n-k-1];
    min_val = a[k-1];
    min_diff = min(min_diff, max_val - min_val);
    
    // Case 3: Remove K/2 elements from both ends if K is even
    if (k % 2 == 0) {
        max_val = a[k/2-1];
        min_val = a[n-k/2];
        min_diff = min(min_diff, max_val - min_val);
    }
    
    // Case 4: Remove (K-1)/2 elements from the beginning and (K+1)/2 from the end if K is odd
    if (k % 2 == 1) {
        max_val = a[(k-1)/2-1];
        min_val = a[n-(k+1)/2];
        min_diff = min(min_diff, max_val - min_val);
    }
    
    cout << fixed << setprecision(0) << min_diff << endl;
    
    return 0;
}