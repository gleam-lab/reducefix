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
    // The optimal strategy is to remove some prefix and suffix such that total removed = k.
    // Try all possible splits: remove i from left, k-i from right, for i in [0, k]
    long long min_diff = 1e18;
    
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        int remaining_left = left_removed;
        int remaining_right = n - 1 - right_removed;
        
        if (remaining_left <= remaining_right) {
            long long diff = v[remaining_right] - v[remaining_left];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}