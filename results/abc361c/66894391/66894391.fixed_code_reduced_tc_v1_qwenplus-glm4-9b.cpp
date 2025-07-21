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
    
    for (int i = 0; i <= k; i++) {
        // Calculate the max and min after removing i elements from the end
        int max_val = a[n - k - i];
        int min_val = a[i];
        
        // Update the minimum difference
        min_diff = min(min_diff, max_val - min_val);
    }
    
    cout << min_diff << endl;
    
    return 0;
}