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
    // Try all possible splits: remove i from left, and (k - i) from right.
    long long min_diff = 1e18;
    
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = n - 1 - (k - i);
        if (left <= right) {
            min_diff = min(min_diff, (long long)(v[right] - v[left]));
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}