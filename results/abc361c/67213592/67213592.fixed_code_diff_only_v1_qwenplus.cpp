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
    // The optimal way is to choose a contiguous segment of (n - k) elements
    // from the sorted array to minimize (max - min).
    int min_diff = v[n - 1] - v[0];
    int len = n - k;
    
    for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        min_diff = min(min_diff, v[j] - v[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}