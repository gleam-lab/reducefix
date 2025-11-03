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
    
    // We need to remove exactly K elements
    // The remaining sequence will have n-k elements
    // We want to minimize (max - min) of the remaining elements
    // Since the array is sorted, we can consider contiguous segments of length n-k
    // The answer is the minimum difference between last and first element in any such segment
    
    int min_diff = INT_MAX;
    int remaining = n - k;
    
    // Try all possible contiguous subarrays of length (n-k)
    for (int i = 0; i + remaining - 1 < n; i++) {
        int diff = a[i + remaining - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}