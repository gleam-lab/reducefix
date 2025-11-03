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
    
    int min_diff = INT_MAX;
    // Try removing k elements: remove i from left and (k-i) from right
    for (int i = 0; i <= k; i++) {
        int left = i;
        int right = n - 1 - (k - i);
        if (left <= right) {
            min_diff = min(min_diff, a[right] - a[left]);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}