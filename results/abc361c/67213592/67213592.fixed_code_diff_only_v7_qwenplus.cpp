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
    // So we keep (n - k) consecutive elements from the sorted array
    // The optimal way is to choose a contiguous subarray of length (n - k)
    // Try all possible windows of size (n - k)
    
    int min_diff = v[n - 1] - v[0]; // Initialize with worst case
    int window_size = n - k;
    
    for (int i = 0; i + window_size - 1 < n; i++) {
        int left = i;
        int right = i + window_size - 1;
        min_diff = min(min_diff, v[right] - v[left]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}