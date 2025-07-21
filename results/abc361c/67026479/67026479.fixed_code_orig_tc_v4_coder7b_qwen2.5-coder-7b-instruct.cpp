#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate the differences between consecutive elements
    vector<int> diffs(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diffs[i] = a[i + 1] - a[i];
    }
    
    // Sort the differences
    sort(diffs.begin(), diffs.end());
    
    // Remove the smallest k-1 differences
    int result = a[n - 1] - a[0];
    for (int i = 0; i < k - 1; ++i) {
        result -= diffs[i];
    }
    
    cout << result << endl;
    
    return 0;
}