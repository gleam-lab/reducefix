#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int min_diff = a[n - 1] - a[0];
    
    // Try all possible ways to remove k elements:
    // Remove i elements from the left and (k - i) from the right
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