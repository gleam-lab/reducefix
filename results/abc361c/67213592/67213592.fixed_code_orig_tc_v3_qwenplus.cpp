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
    
    long long min_diff = 1e18;
    
    // Try all possible ways to remove k elements from the ends
    // We can remove i elements from the left and (k-i) from the right
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        
        int left_idx = left_removed;
        int right_idx = n - 1 - right_removed;
        
        if (left_idx <= right_idx) {
            long long diff = (long long)v[right_idx] - v[left_idx];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}