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
    // So we keep (n - k) consecutive elements from the sorted array
    // Try all possible contiguous subarrays of length (n - k)
    int min_diff = a[n - 1] - a[0];
    
    for (int i = 0; i + (n - k) - 1 < n; i++) {
        int j = i + (n - k) - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}