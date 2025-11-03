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
    
    // We are going to remove exactly K elements
    // So we will keep (n - k) consecutive elements in the sorted array
    // The optimal answer must come from some contiguous subarray of length (n-k)
    
    int min_diff = v[n-1] - v[0]; // worst case: keep all elements
    
    // Try all possible contiguous segments of length (n-k)
    int window_size = n - k;
    for (int left = 0; left + window_size - 1 < n; left++) {
        int right = left + window_size - 1;
        min_diff = min(min_diff, v[right] - v[left]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}