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
    
    // If after removal we have only one element, difference is 0
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long min_diff = 1e18;
    
    // Try all possible contiguous segments of length m in the sorted array
    for (int i = 0; i <= n - m; i++) {
        long long diff = a[i + m - 1] - a[i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    return 0;
}