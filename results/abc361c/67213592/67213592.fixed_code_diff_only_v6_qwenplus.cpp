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
    // So we will keep (n - k) elements
    // To minimize (max - min) of remaining elements,
    // we should consider all contiguous subarrays of length (n - k)
    int min_diff = v[n - 1] - v[0]; // Initialize with worst case
    
    int keep = n - k;
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, v[j] - v[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}