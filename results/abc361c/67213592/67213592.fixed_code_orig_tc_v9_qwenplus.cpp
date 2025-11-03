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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The optimal way is to choose a contiguous subarray of length (n - k)
    // from the sorted array, because any non-contiguous selection can be improved.
    int min_diff = v[n - 1] - v[0]; // worst case: entire array range
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, v[j] - v[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}