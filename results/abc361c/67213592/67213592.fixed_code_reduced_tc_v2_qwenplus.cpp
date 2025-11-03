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
    
    // We remove exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    long long min_diff = v[keep - 1] - v[0]; // Initial window: first 'keep' elements
    
    // Try all possible contiguous windows of length 'keep'
    for (int i = 1; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        long long diff = v[j] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}