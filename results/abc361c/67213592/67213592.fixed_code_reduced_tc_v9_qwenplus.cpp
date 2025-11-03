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
    // The optimal way is to remove some prefix and suffix such that total removed = k.
    // Try all possible splits: remove i from left, k-i from right.
    long long min_diff = 1e18;
    int keep = n - k;
    
    for (int left = 0; left <= k; left++) {
        int right = k - left;
        if (left + right > n || keep > n - left - right) continue;
        
        int L = left;
        int R = n - 1 - right;
        if (L <= R) {
            min_diff = min(min_diff, (long long)(v[R] - v[L]));
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}