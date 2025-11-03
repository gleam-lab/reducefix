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
    // The remaining sequence will have n - k elements
    // To minimize (max - min), we should consider contiguous subarrays of length (n-k)
    // in the sorted array, because rearranging doesn't matter (we preserve original order,
    // but after sorting and taking contiguous segment, it corresponds to some valid removal)
    
    int min_diff = a[n - 1] - a[0]; // worst case: all elements
    
    // Try all possible contiguous segments of length (n-k)
    // We can remove k elements by keeping a contiguous block of (n-k) elements
    // Specifically, we can keep elements from index i to i+(n-k)-1
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}