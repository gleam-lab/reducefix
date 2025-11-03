#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }
    
    sort(v.begin(), v.end());
    
    // We are removing exactly K elements
    // The remaining sequence has length = n - k
    // We want to minimize (max - min) of the remaining elements
    // So we try all possible contiguous segments of length (n - k)
    
    int min_diff = v[n - 1] - v[0]; // worst case: entire array
    int remaining_length = n - k;
    
    // Try every possible contiguous subarray of length (n - k)
    for (int i = 0; i + remaining_length - 1 < n; i++) {
        int j = i + remaining_length - 1;
        min_diff = min(min_diff, v[j] - v[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}