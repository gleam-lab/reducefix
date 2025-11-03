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
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The optimal way is to remove some prefix and suffix such that total removed = k.
    // Try all possible combinations: remove i from left, k-i from right.
    long long min_diff = 1e18;
    
    for (int i = 0; i <= k; i++) {
        int left_removed = i;
        int right_removed = k - i;
        
        int left_index = left_removed;
        int right_index = n - 1 - right_removed;
        
        if (left_index <= right_index) {
            min_diff = min(min_diff, (long long)(a[right_index] - a[left_index]));
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}