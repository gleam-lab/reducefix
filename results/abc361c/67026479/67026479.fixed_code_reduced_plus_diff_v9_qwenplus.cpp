#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int m = n - k;
    int min_diff = a[m - 1] - a[0]; // Initialize with first window
    
    // Check all possible contiguous windows of size m
    for(int i = 1; i <= k; i++) {
        if (i + m - 1 < n) {
            int diff = a[i + m - 1] - a[i];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    return 0;
}